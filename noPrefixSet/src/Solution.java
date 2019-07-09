import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/***
 * Given N strings. Each string contains only lowercase letters from a - j (both inclusive).
 * The set of  strings is said to be GOOD SET if no string is prefix of another string else,
 * it is BAD SET. (If two strings are identical, they are considered prefixes of each other.)
 *
 * For example, aab, abcde, aabcd is BAD SET because aab is prefix of aabcd.
 *
 * Print GOOD SET if it satisfies the problem requirement.
 * Else, print BAD SET and the first string for which the condition fails.
 *
 * Input Format
 * First line contains , the number of strings in the set.
 * Then next  lines follow, where  line contains  string.
 *
 * Constraints
 *  1 <= N <= 10ˆ5
 *  1 <= Length of string <= 60
 *
 * Output Format
 * Output GOOD SET if the set is valid.
 * Else, output BAD SET followed by the first string for which the condition fails.
 *
 * Sample Input00
 * 7
 * aab
 * defgab
 * abcde
 * aabcde
 * cedaaa
 * bbbbbbbbbb
 * jabjjjad
 *
 * Sample Output00
 * BAD SET
 * aabcde
 */
public class Solution {

  private static final Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    PrefixSet prefixSet = new PrefixSet();

    int queriesRows = Integer.parseInt(scanner.nextLine().trim());

    for (int i = 0; i < queriesRows; i++) {
      String[] word = scanner.nextLine().split(" ");
      String string = word[0];
      if(!prefixSet.addWord(string)){
        System.out.println("BAD SET");
        System.out.println(string);
        return;
      }

    }

    System.out.println("GOOD SET");

  }

}

class PrefixSet {

  private Set<String> words = new HashSet<>();
  private Set<String> prefixies = new HashSet<>();

  public Boolean addWord(String word){

    if(!words.add(word))
      return false;

    for (int i = word.length(); i >= 0; i --) {
      String prefix = word.substring(0, i);
      if(!prefixies.add(prefix) && words.contains(prefix)) {
        return false;
      }
    }

    return  true;
  }

}
