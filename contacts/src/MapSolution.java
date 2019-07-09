import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

class MapSolution {

  Map<String, Integer> namesMap = new HashMap<>();

  void addName(String name){

    for (int i = 0; i < name.length(); i++) {
      String substring = name.substring(0, i + 1);
      Integer qty = namesMap.get(substring);
      if(Objects.isNull(qty))
        qty = 0;

      namesMap.put(substring, qty + 1);
    }
  }


  int searchQuantity(String partial) {
    Integer qty = namesMap.get(partial);
    return Objects.isNull(qty) ? 0 : qty;
  }
}
