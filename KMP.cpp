/**********************************************************************************
 *                                                                                *
 *                                KMP Algorithm                                   *
 *                    (Knuth-Morris-Pratt String Search Algorithm)                *
 *                                                                                *
 * This program implements the Knuth-Morris-Pratt (KMP) algorithm,                *
 * an efficient string matching algorithm that finds occurrences of               *
 * a word (or pattern) within a main text string. The algorithm                   *
 * achieves this by pre-processing the pattern to create a partial match          *
 * (or "longest prefix suffix") table, which helps in avoiding unnecessary        *
 * re-comparisons of characters in the main text.                                 *
 *                                                                                *
 * License:                                                                       *
 * This program is free to use, modify, and distribute under any conditions.      *
 * It is provided "as is" without any warranty of any kind, expressed or implied. *
 *                                                                                *
 * Contact:                                                                       *
 * If you encounter any issues, bugs, or have suggestions for improvements,       *
 * feel free to contact me at:                                                    *
 * E-mail: zerocool_m12@hotmail.com                                               *
 *                                                                                *
 * Written by: Mohammed Fawaz                                                     *
 * Date: 23rd August 2024                                                         *
 *                                                                                *
 **********************************************************************************/

#include<iostream>
#include<string>
#include<vector>
void calc_lps(const std::string&,std::vector<std::size_t>&, const std::size_t&);
void kmp_search(const std::string&, const std::string&);
int main(){
  std::cout<<"Please enter the text:-"<<std::endl;
  std::string str;
  std::getline(std::cin>>std::ws,str);            // getting rid of the unnecessary leading whitespace
  std::cout<<"Please enter the word you are searching for:-"<<std::endl;
  std::string substr;
  std::getline(std::cin>>std::ws,substr);
  kmp_search(str,substr);
  std::cout<<"Press Enter to close this window..."<<std::endl;
  std::cin.get();  
  return EXIT_SUCCESS;
}
void calc_lps(const std::string & str,std::vector<std::size_t>&lps,const std::size_t&n){
  std::size_t len = 0;
  std::size_t i = 1;
  lps[0] = 0;
  while(i not_eq n){
    if(str[i] == str[len]){
      len++;
      lps[i] = len;
      i++;
    }else{
      if(len not_eq 0)
        len = lps[len-1];
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
}
void kmp_search(const std::string&str, const std::string&substr){
  if(str.empty() or substr.empty()){     // checking whether any of the strings is empty
    std::cerr<<"Unable to process empty!"<<std::endl;
    return;
  }
  std::size_t n = str.length();
  std::size_t m = substr.length();
  if(m > n){         // checking whether the size of the pattern is larger than the text 
    std::cerr<<"The word is longer than the text!"<<std::endl;
    return;
  }
  std::vector<std::size_t>lps(m,0);
  calc_lps(substr,lps,m);
  std::size_t i = 0, j = 0, count = 0;
  while(i not_eq str.size()){
    if(str[i] == substr[j]){
      i++;
      j++;
    }
    if(j == m){
      std::cout<<"The word has been found at index: "<<i-j<<std::endl;
      count++;              // counting the matches
      j = lps[j-1];
    }else if(str[i] not_eq substr[j] and i not_eq n){
      if(j not_eq 0)
        j = lps[j - 1];
        else i++;
    }
  }
  if(count > 0)
    std::cout<<"Search done! The word has been found: "<<count<<" times"<<std::endl;
  else std::cerr<<"Search done! Unable to find the word!"<<std::endl;
}