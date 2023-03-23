#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}

 static const vector<string> filenames = {
            "00.txt", // articles
            "01.txt", // determiners
            "20.txt", // pronoun
            "10.txt", // Indian Names
            "12.txt", // Plural nouns
            "14.txt", // Names
            "11.txt", // Singular Nouns
            "13.txt", // posessive nouns
            "30.txt", // auxiliary verbs
            "31.txt", // verb 1
            "32.txt", // verb 2
            "33.txt", // verb 3
            "34.txt", // verb 4
            "35.txt", // verb 5
            "40.txt", // adjective
            "50.txt", // adverb
            "60.txt", // preposition
            "70.txt", // conjunction
            "80.txt"  // interjection
};

string auxVerbmapping(string s)
{
    map<string, string> mmap;
    mmap["am"] = "a0";
    mmap["is"] = "b0";
    mmap["are"] = "c0";
    mmap["was"] = "d0";
    mmap["were"] = "e0";
    mmap["have"] = "f0";
    mmap["has"] = "g0";
    mmap["had"] = "h0";
    mmap["been"] = "i0";
    mmap["will"] = "j0";
    mmap["would"] = "k0";
    mmap["may"] = "l0";
    mmap["might"] = "m0";
    mmap["can"] = "n0";
    mmap["could"] = "o0";
    mmap["shall"] = "p0";
    mmap["should"] = "q0";
    mmap["must"] = "r0";
    mmap["ought"] = "s0";
    mmap["need"] = "t0";
    mmap["do"] = "u0";
    mmap["did"] = "v0";
    mmap["does"] = "w0";
    map<string, string>::iterator it;
    for (auto it = mmap.begin(); it != mmap.end(); it++)
        if (it->first == s)
            return it->second;
}

string pronounMapping(string s)
{
    map<string, string> mmap;
    mmap["i"] = "aa";
    mmap["anybody"] = "ae";
    mmap["anyone"] = "af";
    mmap["anything"] = "ag";
    mmap["everybody"] = "am";
    mmap["everyone"] = "an";
    mmap["everything"] = "ao";
    mmap["he"] = "aq";
    mmap["him"] = "au";
    mmap["through"] = "ax";
    mmap["it"] = "ay";
    mmap["little"] = "bb";
    mmap["many"] = "bc";
    mmap["me"] = "bd";
    mmap["mine"] = "be";
    mmap["much"] = "bh";
    mmap["nobody"] = "bn";
    mmap["none"] = "bo";
    mmap["another"] = "br";
    mmap["others"] = "bt";
    mmap["ourselves"] = "bw";
    mmap["through"] = "bx";
    mmap["several"] = "by";
    mmap["she"] = "bz";
    mmap["somebody"] = "cb";
    mmap["someone"] = "cc";
    mmap["something"] = "cd";
    mmap["theirs"] = "cg";
    mmap["them"] = "ch";
    mmap["they"] = "ck";
    mmap["us"] = "cn";
    mmap["we"] = "co";
    mmap["who"] = "ct";
    mmap["whoever"] = "cu";
    mmap["whom"] = "cv";
    mmap["whomever"] = "cw";
    mmap["whose"] = "cx";
    mmap["you"] = "cy";
    mmap["yours"] = "da";
    mmap["i'm"] = "db";
    map<string, string>::iterator it;
    for (auto it = mmap.begin(); it != mmap.end(); it++)
        if (it->first == s)
            return it->second;
}

string fileMapping(string s)
{
    map<string, string> mmap;
    mmap["00.txt"] = "Articles";
    mmap["01.txt"] = "Determiners";
    mmap["10.txt"] = "Noun";
    mmap["11.txt"] = "Noun";
    mmap["12.txt"] = "Noun";
    mmap["13.txt"] = "Noun";
    mmap["14.txt"] = "Noun";
    mmap["20.txt"] = "Pronoun";
    mmap["30.txt"] = "Verb";
    mmap["31.txt"] = "Verb";
    mmap["32.txt"] = "Verb";
    mmap["33.txt"] = "Verb";
    mmap["34.txt"] = "Verb";
    mmap["35.txt"] = "Verb";
    mmap["40.txt"] = "Adjective";
    mmap["50.txt"] = "Adverb";
    mmap["60.txt"] = "Preposition";
    mmap["70.txt"] = "Conjuction";
    mmap["80.txt"] = "Interjection";

    map<string, string>::iterator it;
    for (auto it = mmap.begin(); it != mmap.end(); it++)
        if (it->first == s)
            return it->second;
}