#include <fstream>
#include <string>
#include "MTH.h"

using namespace std;

namespace MarkdownToHTML {

    class MTH {
    private:
    
        //读取文本
        string read_file(string filename) {
            ifstream file(filename);
            string content;
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    content += line + '\n';
                }
                file.close();
            }
            return content;
        }

        string replaceTitleAndAddEndTag(const string& input) {   //尝试查找并替换“#”并在后面的换行符前添加</h1>
            string result = input;
            size_t pos = 0;
            while ((pos = result.find('#', pos))!= string::npos) {
                // 从#出现的位置往后找换行符
                size_t newlinePos = result.find('\n', pos);
                if (newlinePos!= string::npos) {
                    // 将#替换为<h1>
                    result.replace(pos, 1, "<h1>");
                    // 在换行符前添加</h1>
                    result.insert(newlinePos, "</h1>");
                    pos = newlinePos + 5;  // 更新下次查找的起始位置，跳过刚添加的</h1>和换行符
                } else {
                    // 如果后面没有换行符了，直接在末尾添加</h1>
                    result += "</h1>";
                    break;
                }
            }
            return result;
        }
        
        string replaceTitleAndAddEndTags(const string& input) {
            string result = input;
            size_t pos = 0;
            while ((pos = result.find('#', pos))!= string::npos) {
                // 统计连续#的个数，以确定标题级别
                size_t hashCount = 0;
                while (pos + hashCount < result.size() && result[pos + hashCount] == '#') {
                    hashCount++;
                }
                if (hashCount >= 1 && hashCount <= 6) {  //处理1到6级标题
                    // 构建对应的HTML标题标签，如<h2>、<h3>等
                    string hTag = "<h" + to_string(hashCount) + ">";
                    // 从最后一个#出现的位置往后找换行符
                    size_t newlinePos = result.find('\n', pos + hashCount - 1);
                    if (newlinePos!= string::npos) {
                        // 将连续的#替换为对应的HTML标题标签
                        result.replace(pos, hashCount, hTag);
                        // 在换行符前添加对应的结束标签，如</h2>、</h3>等
                    string endHTag = "</h" + to_string(hashCount) + ">";
                        result.insert(newlinePos, endHTag);
                        pos = newlinePos + endHTag.size();  // 更新下次查找的起始位置，跳过刚添加的结束标签和换行符
                    } else {
                        // 如果后面没有换行符了，直接在末尾添加结束标签
                    string endHTag = "</h" + to_string(hashCount) + ">";
                        result += endHTag;
                        break;
                    }
                } else {
                    pos++;
                }
            }
            return result;
        }
    
    public:

        //主要调用的函数
        string MarkdownToHTML (string md_file_name) {
            string md = read_file(md_file_name);

            return md;
        }

    };
}