#include "head.h"
#include <bits/stdc++.h>
using namespace std;

class Grammar
{
private:
    string str;
    vector<string> word_store;
    string seq;

public:
    Grammar(string str)
    {
        this->str = str;
        seq = "";
    }
    void base_check()
    {
        int size = str.size();

        if (!(str[0] >= 65 && str[0] <= 90))
        {
            cout << "First Letter must be Capital.";
            exit(1);
        }
        // Checking Last Punctuation
        else if ((str[size - 1] != '.') && (str[size - 1] != '?') && (str[size - 1] != '!'))
        {

            cout << "Syntatically InCorrect Punctuation";
            exit(1);
        }
    }

    bool Intercheck(string search, string file)
    {

        ifstream fin;
        fin.open(file);

        if (fin.fail())
        {
            cout << "File opening failed.\n";
            exit(1);
        }
        bool isFound = 0;
        while (!fin.eof())
        {
            string temp = "";
            getline(fin, temp);
            for (int i = 0; i < search.size(); i++)
            {
                if (temp[i] == search[i])
                    isFound = 1;
                else
                {
                    isFound = 0;
                    break;
                }
            }

            if (isFound)
            {
                return isFound;
            }
        }
        return isFound;
    }

    void queCheck()
    {
        string first = firstWord(str);
        int size = str.size();

        string temp = '\"' + first + '\"';

        if (Intercheck(first, "question_words.txt") && str[size - 1] != '?')
        {
            cout << "Not A Question Sentence";
            exit(1);
        }
        else if (str[size - 1] == '?' && !(Intercheck(first, "question_words.txt") || Intercheck(temp, "30.txt")))
        {
            cout << "Not A Question Sentence";
            exit(1);
        }
    }

    void excCheck()
    {
        int size = str.size();
        if (str[size - 1] == '!')
        {
            string first = "\"";
            for (int i = 0; i < size; i++)
            {
                if (str[i] != ',')
                {
                    if (str[i] >= 65 && str[i] <= 90)
                        first += str[i] + 32;
                    else
                        first += str[i];
                }
                else
                {
                    first += "!\"";
                    break;
                }
            }
            if (Intercheck(first, "80.txt") == 0)
            {
                cout << "Not an Excalmation Sentence";
                exit(1);
            }
        }
    }

    vector<string> searchWordInFiles(string word, vector<string> filenames)
    {
        vector<string> foundFiles;
        // cout<<word<<endl;
        for (auto &filename : filenames)
        {
            ifstream file(filename);
            if (file.is_open())
            {
                string line;
                while (getline(file, line))
                {
                    if (line.find(word) != string::npos)
                    {
                        foundFiles.push_back(filename);
                        break;
                    }
                }
                file.close();
            }
            else
            {
                cout << "Unable to open file: " << filename << endl;
            }
        }

        return foundFiles;
    }

    int multifile(string word)
    {
        int count = 0;
        int size = word.size();

        if (Intercheck(word, "00.txt") || Intercheck(word, "01.txt"))
            count++;

        if (Intercheck(word, "10.txt") || Intercheck(word, "11.txt") ||
            Intercheck(word, "12.txt") || Intercheck(word, "13.txt") || Intercheck(word, "14.txt"))
            count++;

        count += Intercheck(word, "20.txt");

        if (Intercheck(word, "30.txt") || Intercheck(word, "31.txt") ||
            Intercheck(word, "32.txt") || Intercheck(word, "33.txt") ||
            Intercheck(word, "34.txt") || Intercheck(word, "35.txt"))
            count++;

        count += Intercheck(word, "40.txt");
        count += Intercheck(word, "50.txt");
        count += Intercheck(word, "60.txt");

        count += Intercheck(word, "70.txt");
        string temp = word;
        if (temp[size - 2] != '!')
        {
            temp[size - 1] = '!';
            temp = temp + '\"';
        }
        count += Intercheck(temp, "80.txt");

        return count;
    }

    string firstWord(string str)
    {
        int size = str.size();

        string first;
        for (int i = 0; i < size; i++)
        {
            if (str[i] != ' ')
            {
                first += str[i];
            }
            else
            {
                break;
            }
        }

        first[0] = first[0] + 32;

        return first;
    }

    void article_check(string word, int i)
    {
        int size = str.size();
        if (word == "a")
        {
            if (str.size() < i + 2)
            {
                cout << "Article used wrong.";
                exit(1);
            }
            else if ((str[i + 1] == 'a') || (str[i + 1] == 'e') || (str[i + 1] == 'i') || (str[i + 1] == 'o') || (str[i + 1] == 'u'))
            {
                cout << "Article used wrong.";
                exit(1);
            }
        }
        else if (word == "an")
        {
            if (str.size() < i + 2)
            {
                cout << "Article used wrong.";
                exit(1);
            }
            if (!((str[i + 1] == 'a') || (str[i + 1] == 'e') || (str[i + 1] == 'i') || (str[i + 1] == 'o') || (str[i + 1] == 'u')))
            {
                cout << "Article used wrong.";
                exit(1);
            }
        }
    }

    void noun_capital()
    {
        for (int i = 1; i < word_store.size(); i++)
        {
            string temp = "\"" + word_store[i] + "\"";
            if (Intercheck(temp, "10.txt") || Intercheck(temp, "13.txt"))
            {
                if (word_store[i][0] < 65 || word_store[i][0] > 90)
                {
                    cout << "Noun \"" << word_store[i] << "\" must be capital.";
                    exit(1);
                }
            }
        }
    }

    void article_use()
    {
    for (int i = 0; i < word_store.size(); i++)
    {
        if (word_store[i] == "the" || word_store[i] == "The" || word_store[i] == "an" || word_store[i] == "An" || word_store[i] == "a" || word_store[i] == "A")
        {
            string temp = "\"" + word_store[i + 1] + "\"";
            if (temp[1] >= 65 && temp[1] <= 90)
            {
                temp[1] += 32;
            }
            if (!(Intercheck(temp, "11.txt") || Intercheck(temp, "40.txt") ||
                  Intercheck(temp, "12.txt") || Intercheck(temp, "13.txt") || Intercheck(temp, "14.txt")))
            {
                cout << "Article used wrong.";
                exit(1);
            }
        }
  }}

    void storeWordInVec()
    {

        int size = str.size();
        string word;

        for (int i = 0; i < size; i++)
        {
            if ((str[i] >= 97 && str[i] <= 122) || (str[i] == '!' && i != size - 1) || (str[i] == '-') || (str[i] == 39))
            {
                // ASCII 39 for apostrophe
                word += str[i];
            }
            else if (str[i] >= 65 && str[i] <= 90)
            {
                word += str[i];
            }
            else if (str[i] == ',' && str[size - 1] == '!')
            {
                word += '!';
            }
            else if (str[i] == ',')
            { //  Space after comma is must.
            }
            else if (str[i] == ' ')
            {
                word_store.push_back(word);

                article_check(word, i);

                if (word_store.size() > 1 && word != "I")
                {
                    for (int j = 0; j < word.size(); j++)
                    {
                        if (j == 0 && (word[0] >= 65 && word[0] <= 90))
                        {
                            string word_temp = "\"" + word + "\"";
                            if (word_temp[1] >= 65 && word_temp[1] <= 90)
                                word_temp[1] += 32;
                            // cout<<word_temp<<endl;

                            if (Intercheck(word_temp, "14.txt") != 1 && Intercheck(word_temp, "10.txt") != 1 && Intercheck(word_temp, "13.txt") != 1)
                            {
                                cout << "Wrong UpperCase";
                                exit(1);
                            }
                        }
                        if (j != 0 && (word[j] >= 65 && word[j] <= 90))
                        {
                            cout << "Wrong UpperCase";
                            exit(1);
                        }
                    }
                }

                word = "";
            }
            else if (((str[i] == '.') || (str[i] == '?') || (str[i] == '!')) && i == size - 1)
            {
                word_store.push_back(word);

                if (word_store.size() > 1 && word != "I")
                {
                    for (int j = 0; j < word.size(); j++)
                    {
                        if (j == 0 && (word[0] >= 65 && word[0] <= 90))
                        {
                            string word_temp = "\"" + word + "\"";
                            if (word_temp[1] >= 65 && word_temp[1] <= 90)
                                word_temp[1] += 32;
                            // cout<<word_temp<<endl;

                            if (Intercheck(word_temp, "14.txt") != 1 && Intercheck(word_temp, "10.txt") != 1 && Intercheck(word_temp, "13.txt") != 1)
                            {
                                cout << "Wrong UpperCase";
                                exit(1);
                            }
                        }
                        if (j != 0 && (word[j] >= 65 && word[j] <= 90))
                        {
                            cout << "Wrong UpperCase";
                            exit(1);
                        }
                    }
                }

                word = "";
                break;
            }
            else
            {
                cout << "Wrong Syntax"; // Other Characters not allowed.
                exit(1);
            }
        }

        for (int i = 1; i < word_store[0].size(); i++)
        {
            if (word_store[0][i] >= 65 && word_store[0][i] <= 90)
            {
                cout << "Wrong Uppercase";
                exit(1);
            }
        }

        for(int i=0;i<word_store.size()-1;i++){                                                // Name + Singular verb Eliminate
            string temp = '\"' + word_store[i] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;

            string temp2 = '\"' + word_store[i + 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;

            if((Intercheck(temp,"10.txt") || Intercheck(temp,"14.txt") || Intercheck(temp,"11.txt") || 
            word_store[i]=="he" || word_store[i]=="He" || word_store[i]=="She" || word_store[i]=="she" ||
             word_store[i]=="It" || word_store[i]=="it") && Intercheck(temp2,"31.txt")){      
                    cout<<"Singular Noun/Pronoun needs singular verb.";
                    exit(1);
            }
        }


        for(int i=0;i<word_store.size()-1;i++){                                                // Plural Noun/ProNoun + Plural verb Eliminate
            string temp = '\"' + word_store[i] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;

            string temp2 = '\"' + word_store[i + 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;

            if((Intercheck(temp,"12.txt") ||  word_store[i]=="I" || word_store[i]=="We" || word_store[i]=="we" || word_store[i]=="you" ||
             word_store[i]=="You" || word_store[i]=="They" || word_store[i]=="they") && Intercheck(temp2,"35.txt")){       
                    cout<<"Plural Noun/Pronoun needs plural verb.";
                    exit(1);
            }
        }

        for(int i=0;i<word_store.size()-1;i++){
            string temp = '\"' + word_store[i] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;

            string temp2 = '\"' + word_store[i + 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;


            if((Intercheck(temp,"10.txt") || Intercheck(temp,"14.txt") || Intercheck(temp,"11.txt")) && Intercheck(temp2,"31.txt")){       // Name + Singular verb Eliminate
                    cout<<"Syntatically Incorrect 00";
                    exit(1);
            }
        }

        for(int i=0;i<word_store.size()-1;i++){
            string temp = '\"' + word_store[i] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)           //Posession + only noun Case
                        temp[1] += 32;

            string temp2 = '\"' + word_store[i + 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;
            if(Intercheck(temp,"13.txt") && !(Intercheck(temp2,"11.txt") || Intercheck(temp2,"12.txt"))){
                    cout<<"Syntatically Incorrect";
                    exit(1);
            }
        }


    }

    void seq_generate()
    {

        vector<char> sequence;

        for (int i = 0; i < word_store.size(); i++)
        {

            string word = word_store[i];

            if (word[0] >= 65 && word[0] <= 90)
            {
                word[0] += 32;
            }

            word = "\"" + word + "\"";

            //cout<<word<<" "<<multifile(word)<<endl<<endl;

            // Determiners Exception
            if (multifile(word) > 1 && (Intercheck(word, "01.txt")) && !(Intercheck(word, "20.txt")))
            {
                sequence.push_back('0');
                sequence.push_back('1');
                continue;
            }


            //Adjective & Adverb     Checked.
           if (multifile(word)== 2 && (Intercheck(word, "40.txt") && Intercheck(word, "50.txt")) )
            {
                 string temp = '\"' + word_store[i + 1] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;

                string temp2 = '\"' + word_store[i - 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;
                    

                if((i + 1 < word_store.size()) && (Intercheck(temp, "11.txt")|| Intercheck(temp, "12.txt") || Intercheck(temp, "11.txt")
                    || Intercheck(temp, "14.txt") || Intercheck(temp, "20.txt")) && multifile(temp)==1) {

                         sequence.push_back('4');
                        sequence.push_back('0');
                        continue;
                }
                else if(i+1==word_store.size() && Intercheck(temp2, "30.txt")){
                        sequence.push_back('4');
                        sequence.push_back('0');
                        continue;
                }
                else{
                    sequence.push_back('5');
                    sequence.push_back('0');
                    continue;
                }    
            }

            //Adjective & Verb     Checked.
           if (multifile(word)== 2 && (Intercheck(word, "40.txt") && 

            (Intercheck(word, "31.txt") || 
            Intercheck(word, "32.txt") || Intercheck(word, "33.txt") || Intercheck(word, "34.txt")  || Intercheck(word, "35.txt"))

             ))
            {
                 string temp = '\"' + word_store[i + 1] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;

                string temp2 = '\"' + word_store[i - 1] + '\"';
                    if (temp2[1] >= 65 && temp2[1] <= 90)
                        temp2[1] += 32;
                    

                if((i + 1 < word_store.size()) && (Intercheck(temp, "11.txt")|| Intercheck(temp, "12.txt") || Intercheck(temp, "11.txt")
                    || Intercheck(temp, "14.txt") || Intercheck(temp, "20.txt")) && multifile(temp)==1) {

                         sequence.push_back('4');
                        sequence.push_back('0');
                        continue;
                }
                else if(i+1==word_store.size() && Intercheck(temp2, "30.txt")){
                        sequence.push_back('4');
                        sequence.push_back('0');
                        continue;
                }
                else{
                    if(Intercheck(word, "31.txt") ){
                        sequence.push_back('3');
                        sequence.push_back('1');
                        continue;
                    }
                    else if(Intercheck(word, "32.txt")){
                        sequence.push_back('3');
                        sequence.push_back('2');
                        continue;
                    }
                    else if(Intercheck(word, "33.txt")){
                        sequence.push_back('3');
                        sequence.push_back('3');
                        continue;
                    }
                    else if(Intercheck(word, "34.txt")){
                        sequence.push_back('3');
                        sequence.push_back('4');
                        continue;
                    }
                    else if(Intercheck(word, "35.txt")){
                        sequence.push_back('3');
                        sequence.push_back('5');
                        continue;
                    }
                }   
            }



            // Noun and Adjective
            if (multifile(word) > 1 && Intercheck(word, "11.txt") && Intercheck(word, "40.txt"))
            {
                // cout<<"Adj vs Noun Flag 1"<<endl;
                if (i + 1 < word_store.size())
                {
                    string temp = '\"' + word_store[i + 1] + '\"';
                    if (temp[1] >= 65 && temp[1] <= 90)
                        temp[1] += 32;
                    if (Intercheck(temp, "01.txt") || Intercheck(temp, "10.txt") || Intercheck(temp, "11.txt") || Intercheck(temp, "12.txt") ||
                        Intercheck(temp, "13.txt") || Intercheck(temp, "14.txt") || Intercheck(temp, "20.txt"))
                    {
                        sequence.push_back('4');
                        sequence.push_back('0');
                        continue;
                    }
                    else
                    {
                        sequence.push_back('1');
                        sequence.push_back('1');
                        continue;
                    }
                }
                else
                {
                    sequence.push_back('1');
                    sequence.push_back('1');
                    continue;
                }
            }

            // Gerund and verb -> ing form
            if (i != 0 && multifile(word) > 1)
            {
                if (Intercheck(word, "34.txt") && Intercheck(word, "11.txt"))
                {
                    sequence.push_back('3');
                    sequence.push_back('4');
                    continue;
                }
            }
            if (i == 0 && multifile(word) > 1)
            {
                if (Intercheck(word, "11.txt") &&
                    (Intercheck(word, "31.txt") || Intercheck(word, "32.txt") || Intercheck(word, "33.txt") || Intercheck(word, "34.txt") || Intercheck(word, "35.txt")))
                {
                    sequence.push_back('1');
                    sequence.push_back('1');
                    continue;
                }
            }

            if (multifile(word) > 1 && Intercheck(word, "60.txt"))
            {
                sequence.push_back('6');
                sequence.push_back('0');
                continue;
            }

            // Noun & Verb Check
            if (i != 0 && multifile(word) > 1 && Intercheck(word, "11.txt") && Intercheck(word, "31.txt"))
            {
                string temp = '\"' + word_store[i - 1] + '\"';
                if (temp[1] >= 65 && temp[1] <= 90)
                    temp[1] += 32;

                if (Intercheck(temp, "01.txt") || Intercheck(temp, "00.txt"))
                {
                    sequence.push_back('1');
                    sequence.push_back('1');
                    continue;
                }
                else if (Intercheck(temp, "20.txt"))
                {
                    sequence.push_back('3');
                    sequence.push_back('1');
                    continue;
                }
                else if (Intercheck(temp, "60.txt"))
                {
                    sequence.push_back('1');
                    sequence.push_back('1');
                    continue;
                }
                else
                {
                    sequence.push_back('3');
                    sequence.push_back('1');
                    continue;
                }
            }
            else if (i == 0 && multifile(word) > 1 && Intercheck(word, "11.txt") && Intercheck(word, "31.txt"))
            {
                sequence.push_back('1');
                sequence.push_back('1');
                continue;
            }

            // Preposition and Conjuction
            if (multifile(word) > 1 && Intercheck(word, "60.txt") && Intercheck(word, "70.txt"))
            {
                string temp = '\"' + word_store[i + 1] + '\"';
                if (temp[1] >= 65 && temp[1] <= 90)
                    temp[1] += 32;
                if (Intercheck(temp, "01.txt") || Intercheck(temp, "11.txt") || Intercheck(temp, "12.txt") ||
                    Intercheck(temp, "13.txt") || Intercheck(temp, "14.txt") || Intercheck(temp, "20.txt"))
                {
                    sequence.push_back('6');
                    sequence.push_back('0');
                    continue;
                }
            }

            if ((multifile(word)) > 1)
            {
                cout << "No Expertise" << endl;
                vector<string> foundFiles = searchWordInFiles(word, filenames);
                string temp = word;
                int t = word.size();
                temp[t - 1] = '!';
                temp = temp + '\"';
                if (Intercheck(temp, "80.txt"))
                {
                    foundFiles.push_back("80.txt");
                }
                vector<string> print;
                cout << "Word " << word << " can behave like : " << endl;
                for (const auto &filename : foundFiles)
                {
                    int f = 0;
                    for (int k = 0; k < print.size(); k++)
                    {
                        if (print[k] == fileMapping(filename))
                        {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0)
                    {
                        print.push_back(fileMapping(filename));
                        cout << fileMapping(filename) << endl;
                    }
                }
                exit(1);
            }

            if ((multifile(word)) < 1)
            {
                cout << "Word " << word << " doesn't exist. " << endl;
                exit(1);
            }

            bool foundFile;
            string Fname, foundFiles;

            for (int i = 0; i < filenames.size(); i++)
            {
                Fname = filenames[i];

                foundFile = Intercheck(word, Fname);

                if (foundFile)
                {
                    foundFiles = Fname;
                    break;
                }
            }

            if (foundFiles[0] == '3' && foundFiles[1] == '0')
            { // pushing auxilary verb
                string temp;
                for (int j = 0; j < word.size(); j++)
                {
                    if (word[j] != '"')
                    {
                        temp += word[j];
                    }
                }
                temp = auxVerbmapping(temp); // Mapping Pronouns and Pushing it in char vec
                sequence.push_back(temp[0]);
                sequence.push_back(temp[1]);
            }

            else if (foundFiles[0] == '2' && foundFiles[1] == '0')
            { // pushing pronoun
                string temp;
                for (int j = 0; j < word.size(); j++)
                {
                    if (word[j] != '"')
                    {
                        temp += word[j];
                    }
                }
                temp = pronounMapping(temp); // Mapping Aux Verb and Pushing it in char vec
                sequence.push_back(temp[0]);
                sequence.push_back(temp[1]);
            }

            else
            {
                sequence.push_back(foundFiles[0]);
                sequence.push_back(foundFiles[1]);
            }
        }
        for (int i = 0; i < sequence.size(); i++)
        {
            if (i == 0)
                seq += '\"';

            seq += sequence[i];
        }
        seq += '\"';
    }

    void check_seq()
    {

        if (Intercheck(seq, "predefined_sequences.txt"))
        {
            cout << "Syntatically Correct";
            //cout<<endl<<"Generated Sequence : "<<seq;
        }
        else
        {
            cout << "Syntatically Incorrect Sentence" << endl;
           // cout << "Generated Sequence : " << seq;
        }
    }
};
int main()
{

    init_code();

    string str;
    getline(cin, str);

    Grammar Sen(str);

    Sen.base_check();

    Sen.queCheck();

    Sen.excCheck();

    Sen.storeWordInVec();

    Sen.noun_capital();

    Sen.article_use();

    Sen.seq_generate();

    Sen.check_seq();
    return 0;
}