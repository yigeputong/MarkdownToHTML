/* Copyright (c) yigeputong 2024-2024 */

#ifndef MTH_H
#define MTH_H

#include <fstream>
#include <string>

using namespace std;

namespace mth {
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
        }/*
        pos = 0;
        while ((pos = result.find('##', pos))!= string::npos) {
            // 从#出现的位置往后找换行符
            size_t newlinePos = result.find('\n', pos);
            if (newlinePos!= string::npos) {
                // 将#替换为<h1>
                result.replace(pos, 1, "<h2>");
                // 在换行符前添加</h1>
                result.insert(newlinePos, "</h2>");
                pos = newlinePos + 5;  // 更新下次查找的起始位置，跳过刚添加的</h1>和换行符
            } else {
                // 如果后面没有换行符了，直接在末尾添加</h1>
                result += "</h1>";
                break;
            }
        }/*
        pos = 0;
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
        }/*
        pos = 0;
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
        }/*
        pos = 0;
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
        }/*
        pos = 0;
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
        }*/
        return result;
    }

    string MarkdownToHTML (string md_file) {
        string md = mth::read_file(md_file);

        return md;
    }
}

#endif