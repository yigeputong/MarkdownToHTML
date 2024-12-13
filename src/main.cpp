#include <iostream>
#include "MTH.h"

int main(char* argv[]) {
    if (argv[1] == nullptr) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string content = "<main>\n";

    content += mth::MarkdownToHTML(argv[1]);

    content += "</main>";
    cout << content << endl;
    return 0;
}