import java.util.stream.Stream;

public class MS {
  public static void main(String[] args) {
    // NOTE: The following input values will be used for testing your solution.
    int[][] bombs1 = {{0, 2}, {2, 0}};

    // [[0, 1, -1],
    //  [1, 2, 1],
    //  [-1, 1, 0]]

    int[][] bombs2 = {{0, 0}, {0, 1}, {1, 2}};
    // mineSweeper(bombs2, 3, 4) should return:
    // [[-1, -1, 2, 1],
    //  [2, 3, -1, 1],
    //  [0, 1, 1, 1]]

    int[][] bombs3 = {{1, 1}, {1, 2}, {2, 2}, {4, 3}};
    // mineSweeper(bombs3, 5, 5) should return:
    // [[1, 2, 2, 1, 0],
    //  [1, -1, -1, 2, 0],
    //  [1, 3, -1, 2, 0],
    //  [0, 1, 2, 2, 1],
    //  [0, 0, 1, -1, 1]]

    final int[][] ints = mineSweeper(bombs3, 5, 5);

    for (int i = 0; i < ints.length; i++) {
      for (int j = 0; j < ints[i].length; j++) {
        System.out.print(ints[i][j] + ", ");
      }
      System.out.println();
    }

  }

  // Implement your solution below.
  public static int[][] mineSweeper(int[][] bombs, int numRows, int numCols) {
    int[][] field = new int[numRows][numCols];


    for(int i = 0; i < bombs.length; i++){
      int row = bombs[i][0];
      int col = bombs[i][1];

      field[row][col] = -1;

      for(int _row = row - 1; _row <= row + 1; _row++){
        for(int _col = col -1; _col <= col + 1; _col++){
          if((_row >= 0 && _row < numRows) &&
                  (_col >= 0 && _col < numCols) &&
                  field[_row][_col] > -1){
            field[_row][_col] = field[_row][_col] + 1;
          }
        }
      }
    }

    return field;
  }
}
