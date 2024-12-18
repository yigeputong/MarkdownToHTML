#include <iostream>
#include "MTH.h"

using namespace MarkdownToHTML;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string content = "";
    // bool haveA = false;
    // for (int i = 1; i < argc; ++i) {
    //     if (string(argv[i]) == "-a") {
    //         haveA = true;
    //         content = "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>Document</title>\n</head>\n<body>\n";
    //     }
    // }
    content += "<main>\n";
    
    MTH mth;
    //content += "<h1>Hello</h1>";
    try {
        content += mth.MarkdownToHTML(argv[1]);
    } catch (const runtime_error& e) {
        cout << "发生错误：" << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "发生未知错误" << endl;
    }

    content += "\n</main>\n";
    // if (haveA) {
    //     content += "</body>\n</html>";
    // }
    cout << content << endl;
    return 0;
}