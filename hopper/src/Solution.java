import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class Solution {
  public static void main(String[] args){

    int[] towers = new int[]{4,2,0,0,2,0};

    final Solution solution = new Solution();

    System.out.println(solution.isHoppable(towers));
  }

  public boolean isHoppable(int[] towers){
    Map<Integer, Boolean> memo = new HashMap<>();
    return hoppableChecker(towers, 0, memo);

  }

  public boolean hoppableChecker(int[] towers, int index, Map<Integer, Boolean> memo){
    final Boolean processed = memo.get(index);
    if(Objects.nonNull(processed))
      return processed;

    if(index >= towers.length)
      return false;
    if(towers[index] >= towers.length - index)
      return true;

    for (int i = towers[index]; i >= 1; i--){
      final boolean isHoppable = this.hoppableChecker(towers, index + i, memo);
      memo.put(index+i, isHoppable);
      if(isHoppable)
        return true;
    }

    return false;

  }
}
