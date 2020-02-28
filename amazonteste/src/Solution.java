// IMPORT LIBRARY PACKAGES NEEDED BY YOUR PROGRAM
// SOME CLASSES WITHIN A PACKAGE MAY BE RESTRICTED
// DEFINE ANY CLASS AND METHOD NEEDED
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayDeque;
// CLASS BEGINS, THIS CLASS IS REQUIRED
public class Solution {


  public static void main(String[] args){
    final Solution solution = new Solution();

    List<List<Integer>> grid = new ArrayList<>();

    grid.add(Arrays.asList(1,1,0,0));
    grid.add(Arrays.asList(0,0,1,0));
    grid.add(Arrays.asList(0,1,0,0));
    grid.add(Arrays.asList(1,0,1,1));
    grid.add(Arrays.asList(1,1,1,1));

    System.out.println(solution.numberAmazonTreasureTrucks(5, 4, grid));
  }

  // METHOD SIGNATURE BEGINS, THIS METHOD IS REQUIRED
  int numberAmazonTreasureTrucks(int rows, int column,
                                 List<List<Integer> > grid){

    int quantity = 0;
    ArrayDeque<Point> points =  new ArrayDeque<>();

    for(int row = 0; row < grid.size(); row++){
      for(int col = 0; col < grid.get(row).size(); col ++){
        if(grid.get(row).get(col).equals(1)){
          quantity++;
          points.add(new Point(row, col));
        }
        while(!points.isEmpty()){
          Point point = points.pop();
          grid.get(point.row).set(point.col, -2);
          touchAdjacent(point, grid, points);
        }
      }
    }

    return quantity;

  }
  // METHOD SIGNATURE ENDS

  private void touchAdjacent(Point point, List<List<Integer>> grid, ArrayDeque<Point> points) {

    for(int i = point.row - 1; i <= point.row+1; i++){
      for(int j = point.col - 1; j <= point.col+1; j++){
        if( (i >= 0 && i < grid.size()) && (j >= 0 && j < grid.get(i).size()) &&
                ((i == point.row -1 && j == point.col) ||
                        (i == point.row +1 && j == point.col) ||
                        (i == point.row && j == point.col -1) ||
                        (i == point.row && j == point.col +1)) &&
                grid.get(i).get(j).equals(1)){
          points.add(new Point(i, j));
        }
      }
    }

  }

  class Point {

    int row;
    int col;

    Point(int row, int col){
      this.row = row;
      this.col = col;
    }


  }
}