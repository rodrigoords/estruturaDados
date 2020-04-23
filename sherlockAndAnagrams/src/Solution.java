import java.util.HashMap;
import java.util.Map;

/**
 * Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.
 * For example s = mom , the list of all anagrammatic pairs is [m,m], [mo,om] at positions [[0],[2]], [[0,1], [1,2]] respectively.
 *
 * Function Description
 *
 * Complete the function sherlockAndAnagrams in the editor below. It must return an integer that represents the number of anagrammatic pairs of substrings in s.
 *
 * sherlockAndAnagrams has the following parameter(s):
 *
 * s: a string .
 *
 * Input Format
 *
 * The first line contains an integer q, the number of queries.
 * Each of the next q lines contains a string s to analyze.
 *
 * Constraints
 *
 * 1 <= q <= 10
 * 2 <= |s| <= 100
 *
 * String  contains only lowercase letters on ascii[a-z].
 */
public class Solution {

  public static void main(String[] args){

    System.out.println(Solution.sherlockAndAnagrams("ifailuhkqq"));
  }

  // Complete the sherlockAndAnagrams function below.
  static int sherlockAndAnagrams(String s) {

    int total = 0;
    Map<String, Integer> stringCounter = new HashMap<>();

    for (int i = s.length(); i >= 0 ; i--) {
      for (int j = i - 1; j >= 0 ; j--) {
        stringCounter.put( s.substring(j, i), stringCounter.getOrDefault(s.substring(j, i), 0) + 1);
      }
    }

    for(int i = 1; i < s.length(); i++){
      final String value = s.substring(0, i);
      final String anagram = getAnagram(value);

      final Integer integer = stringCounter.remove(anagram);

      if(integer != null){
        final float calc = integer * ((integer -1) / 2f);
        total += (calc == 0? 1 : calc);
      }
    }

    return total;
  }


  private static String getAnagram(String value){

    String newValue = "";
    for(int i = value.length() -1; i >= 0; i--){
      newValue = newValue + value.charAt(i);
    }

    return newValue;
  }
}
