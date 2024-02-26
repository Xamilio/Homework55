#include <iostream>
#include <string>

using namespace std;

class TextCompressor {
private:
    string text;
public:
    TextCompressor(const string& inputText)
    {
        text = inputText;
    }
    string compText() {
        string compText = "";
        bool fWord = true;

        for (char ch : text) {
            if (ch != ' ') {
                if (fWord) 
                {
                    compText += ch;
                    fWord = false;
                }
                else 
                {
                    if (compText.back() != ' ')
                    {
                        compText += ' ';
                    }
                    compText += ch;
                }
            }
        }
        return compText;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    string inputText = "Это      текст   для    сжатия    ";

    TextCompressor comp(inputText);
    string compText = comp.compText();

    cout << compText << endl;
}