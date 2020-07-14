/**
 * AUTHORS: <Or Mendel>
 */

#include <algorithm>
#include <string>
#include <string.h>
#include <exception>
#include "PhoneticFinder.hpp"
#include <iostream>
#include <bits/stdc++.h> 
#include <sstream>
#include <stdexcept>

using namespace std;



    /**
     * the perplexing letters 
     * and what they should be swapped with
     */
    bool perplexing_letters(char ch1,char ch2)
    {
        if(tolower(ch1)==ch2||tolower(ch2)==ch1)
            return true;

        switch(ch1){
            //v,w
            case 'V': if(ch2 == 'w'|| ch2=='W') return true;
            break;
            case 'v': if(ch2 == 'w'|| ch2=='W') return true;
            break;
            case 'W': if(ch2 == 'v'|| ch2=='V') return true;
            break;
            case 'w': if(ch2 == 'v'|| ch2=='V') return true;
            break;
            
            //b,f,p
            case 'B': if(ch2 == 'f' || ch2 == 'p'||ch2=='F'||ch2=='P') return true;
            break;
            case 'b': if(ch2 == 'f' || ch2 == 'p'||ch2=='F'||ch2=='P') return true;
            break;
            case 'F': if(ch2 == 'b' || ch2 == 'p'||ch2=='B'||ch2=='P') return true;
            break;
            case 'f': if(ch2 == 'b' || ch2 == 'p'||ch2=='B'||ch2=='P') return true;
            break;
            case 'P': if(ch2 == 'b' || ch2 == 'f'||ch2=='B'||ch2=='F') return true;
            break;
            case 'p': if(ch2 == 'b' || ch2 == 'f'||ch2=='B'||ch2=='F') return true;
            break;

            //g,j
            case 'G': if(ch2 == 'j'||ch2=='J') return true;
            break;
            case 'g': if(ch2 == 'j'||ch2=='J') return true;
            break;
            case 'J': if(ch2 == 'g'||ch2=='G') return true;
            break;
            case 'j': if(ch2 == 'g'||ch2=='G') return true;
            break;

            //c,k,q
            case 'C': if(ch2 == 'k' || ch2 == 'q'||ch2=='K'||ch2=='Q') return true;
            break;
            case 'c': if(ch2 == 'k' || ch2 == 'q'||ch2=='K'||ch2=='Q') return true;
            break;
            case 'K': if(ch2 == 'c' || ch2 == 'q'||ch2=='C'||ch2=='Q') return true;
            break;
            case 'k': if(ch2 == 'c' || ch2 == 'q'||ch2=='C'||ch2=='Q') return true;
            break;
            case 'Q': if(ch2 == 'c' || ch2 == 'k'||ch2=='C'||ch2=='K') return true;
            break;
            case 'q': if(ch2 == 'c' || ch2 == 'k'||ch2=='C'||ch2=='K') return true;
            break;

            //s,z
            case 'S': if(ch2 == 'z'||ch2=='Z') return true;
            break;
            case 's': if(ch2 == 'z'||ch2=='Z') return true;
            break;
            case 'Z': if(ch2 == 's'||ch2=='S') return true;
            break;
            case 'z': if(ch2 == 's'||ch2=='S') return true;
            break;

            //d,t
            case 'D': if(ch2 == 't'||ch2=='T') return true;
            break;
            case 'd': if(ch2 == 't'||ch2=='T') return true;
            break;
            case 'T': if(ch2 == 'd'||ch2=='D') return true;
            break;
            case 't': if(ch2 == 'd'||ch2=='D') return true;
            break;

            //o,u
            case 'O': if(ch2 == 'u'||ch2=='U') return true;
            break;
            case 'o': if(ch2 == 'u'||ch2=='U') return true;
            break;
            case 'U': if(ch2 == 'o'||ch2=='O') return true;
            break;
            case 'u': if(ch2 == 'o'||ch2=='O') return true;
            break;

            //i,y
            case 'I': if(ch2 == 'y'||ch2=='Y') return true;
            break;
            case 'i': if(ch2 == 'y'||ch2=='Y') return true;
            break;
            case 'Y': if(ch2 == 'i'||ch2=='I') return true;
            break;
            case 'y': if(ch2 == 'i'||ch2=='I') return true;
            break;

            default: return false;
        }
        return false; 
    }

    /**
     * iterate letters of the words 
     * one by one,
     * if one of the letters in 
     * the words is not perplexing 
     * so we return null otherwise 
     * they are the same word with some
     * perplexing letters
     */
    string match_words(string s1,string s2)
    {
        if(s1.length() != s2.length())
             return "NULL";
        for(int i=0;i<s1.length();i++)
        {
            if(!perplexing_letters(s1[i],s2[i]))
                return "NULL";
        }
        return s1;
    }
   

/**
 * finds the word in the text
 * with the restriction
 * of perplexing letters
 */    
namespace phonetic
{
    string find(string text,string word) 
    {
        //to lower case
        transform(word.begin(), word.end(), word.begin(),[](unsigned char c){ return tolower(c); });
        
        stringstream ss(text);
        string str;
        string ans = "";
        while(ss >> str) {
            string s = match_words(str,word);
            if(s != "NULL")//We found the word, so no need continue searching
            {
                ans = str;
                break;
            } 
        }  
        if(ans == ""){
            throw std::runtime_error(std::string("Did not find the word" +  word + " in the text"));
            //return 0;
        } 
        return ans;
    }
}

    

