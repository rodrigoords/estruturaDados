import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {

  public static void main(String[] args){

    int[][] row = new int[6][2];
    row[0] = new int[]{5,1};
    row[1] = new int[]{2,1};
    row[2] = new int[]{1,1};
    row[3] = new int[]{8,1};
    row[4] = new int[]{10,0};
    row[5] = new int[]{5,0};

    System.out.println(Solution.luckBalance(3, row));
  }

  static int luckBalance(int k, int[][] contests) {

    PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());

    int luck = 0;
    int unlucky = 0;

    for(int i = 0; i < contests.length; i++ ){

      if(contests[i][1] == 0){
        luck+=contests[i][0];
      } else {
        queue.add(contests[i][0]);
      }

    }

    int size = queue.size();
    for(int i = 1; i <= size; i++ ){

      if(i <= k)
        luck+=queue.poll();
      else
        unlucky+=queue.poll();

    }

    return luck - unlucky;
  }
}
