import java.util.ArrayList;
import java.util.List;

public class Solution {
  public static void main(String[] args) {

    final Solution solution = new Solution();

    final List<List<Integer>> result = solution.pascalTriangle(5);


    for (List<Integer> rows : result) {
      System.out.print("[");
      for (Integer row : rows) {
        System.out.print(row + ", ");
      }
      System.out.print("]");
      System.out.println();
    }
    
  }

  public List<List<Integer>> pascalTriangle(Integer rowSize){
    
    List<List<Integer>> pascalTriangle = new ArrayList<>(rowSize);
    
    Integer currentRow = 1;
    
    while (currentRow <= rowSize){

      final ArrayList<Integer> row = new ArrayList<>(currentRow);

      pascalTriangle.add(row);
      
      for (int i = 0; i < currentRow; i++) {
        if(i == 0 || i == currentRow -1){
          row.add(i, 1);
        } else {
          final List<Integer> previousRow = pascalTriangle.get(currentRow - 2);
          row.add(i, previousRow.get(i -1) + previousRow.get(i));
        }
      }
      currentRow++;
    }
    
    return pascalTriangle;
    
  }

}
