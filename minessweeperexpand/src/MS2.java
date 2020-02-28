import java.util.ArrayDeque;

public class MS2 {
  public static void main(String[] args) {
    // NOTE: The following input values will be used for testing your solution.
    int[][] field1 = {{0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 1, -1, 1, 0}};

    // click(field1, 3, 5, 2, 2) should return:
    // [[0, 0, 0, 0, 0],
    //  [0, 1, 1, 1, 0],
    //  [0, 1, -1, 1, 0]]

    // click(field1, 3, 5, 1, 4) should return:
    // [[-2, -2, -2, -2, -2],
    //  [-2, 1, 1, 1, -2],
    //  [-2, 1, -1, 1, -2]]


    int[][] field2 = {{-1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 0, 1, -1}};

    // click(field2, 4, 4, 0, 1) should return:
    // [[-1, 1, 0, 0],
    //  [1, 1, 0, 0],
    //  [0, 0, 1, 1],
    //  [0, 0, 1, -1]]

    // click(field2, 4, 4, 1, 3) should return:
    // [[-1, 1, -2, -2],
    //  [1, 1, -2, -2],
    //  [-2, -2, 1, 1],
    //  [-2, -2, 1, -1]]

    final int[][] clicked = click(field2, 4, 4, 1, 3);

    for (int i = 0; i < clicked.length; i++) {
      for (int j = 0; j < clicked[i].length; j++) {
        System.out.print(clicked[i][j] + ", ");
      }
      System.out.println();
    }
  }

  // Implement your solution below.
  public static int[][] click(int[][] field, int numRows, int numCols, int givenI, int givenJ) {

    final ArrayDeque<int[]> queue = new ArrayDeque<>();

    if(field[givenI][givenJ] != 0) {
      return field;
    } else {
      field[givenI][givenJ] = -2;
      queue.add(new int[]{givenI, givenJ});
    }

    while (!queue.isEmpty()){
      final int[] element = queue.pop();
      for (int i = element[0] - 1; i <= element[0] + 1; i++) {
        for (int j = element[1] -1; j <= element[1] + 1; j++) {
          if((i >= 0 && i < numRows) && (j >= 0 && j < numCols) && field[i][j] == 0){
            field[i][j] = -2;
            queue.add(new int[]{i,j});
          }

        }
      }
    }
    return field;
  }
}
