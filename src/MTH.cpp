#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "MTH.h"

using namespace std;

namespace MarkdownToHTML {

    class MTH {
    private:
    
        //读取文本
        string read_file(string filename) {
            string content;
            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    content += line + '\n';
                }
                file.close();
            } else {
                return "";
            }
            return content;
        }

        //转换标题
        string titles(const string& markdown) {
            string result = markdown;
            // 匹配一级标题（以#开头，后面跟着非#开头的内容直到行尾）
            regex h1Pattern("^#([^#].*)");
            result = regex_replace(result, h1Pattern, "<h1>$1</h1>");
            // 匹配二级标题（以##开头，后面跟着非#开头的内容直到行尾）
            regex h2Pattern("^##([^#].*)");
            result = regex_replace(result, h2Pattern, "<h2>$1</h2>");
            // 匹配三级标题（以上面类推）
            regex h3Pattern("^###([^#].*)");
            result = regex_replace(result, h3Pattern, "<h3>$1</h3>");
            // 匹配四级标题
            regex h4Pattern("^####([^#].*)");
            result = regex_replace(result, h4Pattern, "<h4>$1</h4>");
            // 匹配五级标题
            regex h5Pattern("^#####([^#].*)");
            result = regex_replace(result, h5Pattern, "<h5>$1</h5>");
            // 匹配六级标题
            regex h6Pattern("^######([^#].*)");
            result = regex_replace(result, h6Pattern, "<h6>$1</h6>");
            
            return result;
        }

        // 转换无序列表
        string unordered_lists(const string& markdown) {
            string result = markdown;
            // 正则表达式匹配以 - 或 * 开头的行（改进后可处理行首空格情况等，更精准匹配）
            regex listPattern("^[ \\t]*([\\-\\*])[ \\t]*(.*)$");
            // 先将每一行匹配到的内容替换为 <li> 包裹的形式
            result = regex_replace(result, listPattern, "<li>$2</li>");

            // 使用stringstream来方便地操作字符串，构建最终结果
            stringstream ss(result);
            string line;
            string finalResult;
            bool inList = false;
            while (getline(ss, line)) {
                // 如果当前行是 <li> 开头，说明处于列表中
                if (line.find("<li>") == 0) {
                    if (!inList) {
                        finalResult += "<ul>\n";
                        inList = true;
                    }
                    finalResult += line + "\n";
                } else {
                    if (inList) {
                        finalResult += "</ul>\n";
                        inList = false;
                    }
                    finalResult += line + "\n";
                }
            }
            // 处理最后如果处于列表中，需要闭合 <ul> 标签
            if (inList) {
                finalResult += "</ul>\n";
            }

            return finalResult;
        }

        // 转换链接
        string links(const string& markdown) {
            string result = markdown;
            // 正则表达式匹配链接格式
            regex linkPattern("\\[([^\\]]*)\\]\\(([^\\)]*)\\)");
            result = regex_replace(result, linkPattern, "<a href=\"$2\">$1</a>");
            return result;
        }
    
    public:

        //主要调用的函数
        string MarkdownToHTML (string md_file_name) {
            string md = read_file(md_file_name);
            if (md == "") {
                throw runtime_error("文件打开失败");
            }
            md = titles(md);
            //md = convertUnorderedList(md);
            md = links(md);

            return md;
        }

    };
}