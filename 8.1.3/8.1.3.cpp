#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Include(const char* s, const char* cs)
{
    const char* r = strstr(s, cs);
    if (r != NULL)
        return true;
    else
        return false;
}

char* Change(char* s, const char* cs)
{
    char* t = new char[strlen(s)];
    char* p;
    long int pos1 = 0;
    long int pos3 = 0;
    *t = 0;
    while (p = strstr(s + pos1, cs))
    {
        pos3 = p - s + 3;
        strncat(t, s + pos1, pos3 - pos1 - 3);
        strcat(t, "**");
        pos1 = pos3;
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int countAppearences(char* source, const char* match) {
    int count = 0;
    int pos = 0;
    int numberToSkip = strlen(match);
    char* p;

    while (p = strstr(source + pos, match)) {
        count++;
        pos = p - source + numberToSkip;
    }

    return count;
}

char* replace(char* source, const char* match, const char* replacer) {
    const int matchLen = strlen(match);
    const int replacerLen = strlen(replacer);

    const int baseSourceLength = strlen(source);
    const int numberOfAppearences = countAppearences(source, match);
    const int newSourceLength = baseSourceLength + numberOfAppearences;

    char* newSource = new char[newSourceLength];

    newSource[0] = '\0';

    int copyStart = 0;

    for (int i = 0; i < numberOfAppearences; ++i) {
        const char* idx = strstr(copyStart + source, match);
        const int len = idx - source - copyStart;

        strncat(newSource, copyStart + source, len);
        strncat(newSource, replacer, replacerLen);

        copyStart = len + matchLen;
    }

    strcat(newSource, copyStart + source);

    return newSource;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    const int numberOfPluses = countAppearences(str, "+");
    const int numberOfMunises = countAppearences(str, "-");
    const int numberOfEquals = countAppearences(str, "=");

    cout << endl;
    cout << "Number of pluses: " << numberOfPluses << endl;
    cout << "Number of minuses: " << numberOfMunises << endl;
    cout << "Number of equals: " << numberOfEquals << endl;

    cout << endl;

    char* withoutPluses = replace(str, "++", "***");
    char* withoutMinuses = replace(withoutPluses, "--", "***");
    char* withoutEquals = replace(withoutMinuses, "==", "***");

    cout << withoutEquals << endl;

    return 0;
}
