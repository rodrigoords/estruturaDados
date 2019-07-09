/***
 * We're going to make our own Contacts application! The application must perform two types of operations:
 *
 * add name, where  is a string denoting a contact name. This must store  as a new contact in the application.
 * find partial, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
 * Given  sequential add and find operations, perform each operation in order.
 *
 * Input Format
 *
 * The first line contains a single integer,n , denoting the number of operations to perform.
 * Each line  of the  subsequent lines contains an operation in one of the two forms defined above.
 *
 * Constraints
 * 1 <= n <= 10^5
 * 1 <= name <= 21
 * 1 <= partial <= 21
 * It is guaranteed that  and  contain lowercase English letters only.
 * The input doesn't have any duplicate  for the  operation.
 *
 * Output Format
 *
 * For each find partial operation, print the number of contact names starting with  on a new line.
 *
 * Sample Input
 *
 * 4
 * add hack
 * add hackerrank
 * find hac
 * find hak
 *
 * Sample Output
 *
 * 2
 * 0
 */
public class Solution {

  public static void main(String[] args){

    String[][] input = new String[4][2];
    input[0][0] = "add";
    input[0][1] = "hack";
    input[1][0] = "add";
    input[1][1] = "hackerrank";

    input[2][0] = "find";
    input[2][1] = "hac";
    input[3][0] = "find";
    input[3][1] = "hak";



    int[] result = Solution.contacts(input);

    for (int i : result) {
      System.out.println(i);
    }

  }

  static int[] contacts(String[][] queries) {
    /*
     * Write your code here.
     */
    int[] result = new int[queries.length];
    int index = 0;

    MapSolution mapSolution = new MapSolution();

    for (int i = 0; i < queries.length; i++) {
      if(queries[i][0].equals("add")){
        mapSolution.addName(queries[i][1]);
      } else {
        result[index] = mapSolution.searchQuantity(queries[i][1]);
        index ++;
      }
    }

    int[] returnrray = new int[index];

    System.arraycopy(result, 0, returnrray, 0, index);

    return returnrray;

  }

}


