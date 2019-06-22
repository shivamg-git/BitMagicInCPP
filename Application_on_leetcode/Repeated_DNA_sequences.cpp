// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA. Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
// For example,
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// Return: ["AAAAACCCCC", "CCCCCAAAAA"].

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sLen = s.length();
        vector<string> v;
        if(sLen < 11) return v;
        char keyMap[1<<21]{0};
        int hashKey = 0;
        for(int i = 0; i < 9; ++i) hashKey = (hashKey<<2) | (s[i]-'A'+1)%5;
        for(int i = 9; i < sLen; ++i) {
            if(keyMap[hashKey = ((hashKey<<2)|(s[i]-'A'+1)%5)&0xfffff]++ == 1)
                v.push_back(s.substr(i-9, 10));
        }
        return v;
    }
};

// NOTE:
/*
But the above solution can be invalid when repeated sequence appears too many times, 
in which case we should use unordered_map<int, int> keyMap to replace char keyMap[1<<21]{0}here.
*/