#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> calc()
{
    unordered_map<string, int> words;
    string k;


    getline(cin, k);

    char* c = &k[0];

    char* dim = strtok(c, " ");

    while (dim != 0)
    {
        words[string(dim)]++;
        dim = strtok(0, " ");
    }

    return words;
}

int main()
{
    while (true)
    {
        cout << "Введите строку: " << endl;
        unordered_map<string, int> words = calc();

        int m = -1;
        string m1 = "";
        for (const auto& kv : words)
        {
            if (kv.second > m) {
                m = kv.second;
                m1 = kv.first;
            }
        }

        cout <<"Часто встречающееся слово в строке: " << m1 << endl;
    }
    return 0;
}