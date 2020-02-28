import java.util.*;

public class Solution {

  public static void main(String[] arg){

    final Solution solution = new Solution();

    List<List<Integer>> rows = new ArrayList<>();

    rows.add(Arrays.asList(1,0,0,0,0));
    rows.add(Arrays.asList(0,0,0,0,0));
    rows.add(Arrays.asList(0,0,0,0,0));
    rows.add(Arrays.asList(0,0,0,0,0));

    System.out.println(solution.minimumHours(4, 5, rows));
  }


  int minimumHours(int rows, int columns, List<List<Integer> > grid){

    int hour = 0;
    int quantityToProcess = 0;
    final ArrayDeque<Server> servers = new ArrayDeque<>();

    for(int row = 0; row < grid.size(); row++){
      for(int col = 0; col < grid.get(row).size(); col ++){
        if(grid.get(row).get(col).equals(0))
          quantityToProcess++;
      }
    }

    while (quantityToProcess > 0){

      for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid.get(row).size(); col ++){

          if(grid.get(row).get(col).equals(0)){
            //Check adjacent
            boolean keepSearching = Boolean.TRUE;
            for(int i = row - 1; i <= row+1 && keepSearching; i++){
              for(int j = col - 1; j <= col+1; j++){
                if( (i >= 0 && i < grid.size()) &&
                        (j >= 0 && j < grid.get(i).size()) &&
                        ((i == row -1 && j == col) || (i == row +1 && j == col) || (i == row && j == col -1) || (i == row && j == col +1)) &&
                        grid.get(i).get(j).equals(1)){ //Have at last one server to get file
                  servers.add(new Server(row, col));
                  keepSearching = Boolean.FALSE;
                  break;
                }
              }
            }
          }
        }
      }

      while (!servers.isEmpty()){
        final Server server = servers.pop();
        grid.get(server.row).set(server.col, 1);
        quantityToProcess--;
      }

      hour++;
    }

    return hour;

  }

  class Server {

    Integer row;
    Integer col;

    public Server(Integer row, Integer col) {
      this.row = row;
      this.col = col;
    }

  }
}