import java.io.*;
import java.util.Scanner;
import java.util.TreeSet;

/***
 * Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each of the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in your array.
 *
 * For example, the length of your array of zeros n = 10. Your list of queries is as follows:
 *     a b k
 *     1 5 3
 *     4 8 7
 *     6 9 1
 * add the values of k between the indices a and b inclusive:
 *
 * index->	 1  2  3  4   5   6  7  8  9  10
 * 	        [0, 0, 0, 0,  0,  0, 0, 0, 0, 0]
 * 	        [3, 3, 3, 3,  3,  0, 0, 0, 0, 0]
 * 	        [3, 3, 3, 10, 10, 7, 7, 7, 0, 0]
 * 	        [3, 3, 3, 10, 10, 8, 8, 8, 1, 0]
 *
 * The largest value is 10  after all operations are performed.
 *
 */
public class Solution {

//  public static void main(String[] args){
//    int[][] queries = new int[5][3];
//
//    queries[0][0] = 1;
//    queries[0][1] = 5;
//    queries[0][2] = 3;
//
//    queries[1][0] = 4;
//    queries[1][1] = 8;
//    queries[1][2] = 7;
//
//    queries[2][0] = 6;
//    queries[2][1] = 9;
//    queries[2][2] = 1;
//
//    queries[3][0] = 1;
//    queries[3][1] = 10000;
//    queries[3][2] = 13;
//
//    queries[4][0] = 4;
//    queries[4][1] = 5;
//    queries[4][2] = 2;
//
//    System.out.println(Solution.arrayManipulation(10000, queries));
//
//  }

  public static void main(String[] args) throws IOException {


    final File file = new File(ClassLoader.getSystemClassLoader().getResource("input").getFile());

    final Scanner scanner = new Scanner(file);

    String[] nm = scanner.nextLine().split(" ");

    int n = Integer.parseInt(nm[0]);

    int m = Integer.parseInt(nm[1]);

    int[][] queries = new int[m][3];

    for (int i = 0; i < m; i++) {
      String[] queriesRowItems = scanner.nextLine().split(" ");
      scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

      for (int j = 0; j < 3; j++) {
        int queriesItem = Integer.parseInt(queriesRowItems[j]);
        queries[i][j] = queriesItem;
      }
    }

    System.out.println(bestPerformanceArrayManipulation(n, queries));

    scanner.close();
   }

  // Complete the arrayManipulation function below.
  static long arrayManipulation(int n, int[][] queries) {
    long greatest = 0;
    int[] array = new int[n];

    for (int i = 0; i < queries.length; i++) {

      int a = queries[i][0];
      int b = queries[i][1];
      int k = queries[i][2];

      for(int j = a - 1; j <= b -1; j ++){
        int sum = array[j] + k;
        array[j] = sum;
        if(sum > greatest)
          greatest = sum;
      }
    }
    return greatest;
  }

  static long bestPerformanceArrayManipulation(int n, int[][] queries){
    int[] array = new int[n];

    for (int i = 0; i < queries.length; i++) {
      int a = queries[i][0];
      int b = queries[i][1];
      int k = queries[i][2];

      array[a -1]+=k;
      if(b < n)
        array[b]-=k;
    }
    long max = 0;
    long temp = 0;

    for (int i = 0; i < array.length; i++) {
      temp+=array[i];
      if(temp > max)
        max = temp;
    }

    return max;
  }

}
