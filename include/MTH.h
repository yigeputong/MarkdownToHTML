/* Copyright (c) yigeputong 2024-2024 */

#ifndef MTH_H
#define MTH_H

#include <fstream>
#include <string>

using namespace std;

namespace MarkdownToHTML {

    class MTH {
    private:

        //读取 Markdown 文件
        string read_file(string filename);

        //查找 Markdown 标题并替换
        string replaceTitleAndAddEndTag(const string& input);

    public:

        string MarkdownToHTML (string md_file_name);

    };

}

#endif