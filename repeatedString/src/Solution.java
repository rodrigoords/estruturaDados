/***
 * Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.
 *
 * Given an integer, n, find and print the number of letter a's in the first n letters of Lilah's infinite string.
 *
 * For example, if the string s='abcac' and n=10, the substring we consider is abcacabcac, the first 10 characters of her infinite string.
 * There are 4 occurrences of a in the substring.
 *
 * Function Description
 *
 * Complete the repeatedString function in the editor below. It should return an integer representing the number of occurrences of a in the prefix of length n in the infinitely repeating string.
 *
 * repeatedString has the following parameter(s):
 *
 *  - s: a string to repeat
 *  - n: the number of characters to consider
 *
 *  Input Format
 *
 * The first line contains a single string, .
 * The second line contains an integer, .
 *
 * Constraints
 *
 *  1 <= |s| <= 100
 *  1 <= n <= 10ˆ12
 *
 * For  of the test cases, .
 * Output Format
 *
 * Print a single integer denoting the number of letter a's in the first n letters of the infinite string created by repeating s infinitely many times.
 *
 * Example
 *
 * Sample Input 0
 * aba
 * 10
 *
 * Sample Output 0
 * 7
 */
public class Solution {

  static long repeatedString(String s, long n) {

    int aQuantity = 0;
    int aQuantityBeforeDifference = 0;

    long difference = n % s.length();
    long times = n/s.length();

    for (int i = 0; i < s.toCharArray().length; i++) {
      if(String.valueOf(s.charAt(i)).equals("a")){
        aQuantity++;

        if(i < difference )
          aQuantityBeforeDifference++;
      }

    }

    return ( aQuantity * times ) + aQuantityBeforeDifference;

  }

  public static void main(String[] args){
    System.out.println(Solution.repeatedString("aba", 10));
  }
}
