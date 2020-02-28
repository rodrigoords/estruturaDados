import java.util.Map;
import java.util.TreeMap;

public class Main {

  public static void main(String[] args){

    int number[] = new int[]{1,3,5,2,4,6,7};

    System.out.println(Main.minimumSwaps(number));

  }

  static int minimumSwaps(int[] arr) {

    int count = 0;
    final TreeMap<Integer, Integer> sortedArr = new TreeMap<>();

    for (int i = 0; i < arr.length; i++) {
      sortedArr.put(arr[i], i);
    }

    for (int i = 0; i < arr.length; i++){
      final Map.Entry<Integer, Integer> entry = sortedArr.firstEntry();

      if(arr[i] > entry.getKey()){

        int aux = arr[i];
        arr[i] = entry.getKey();
        arr[entry.getValue()] = aux;

        sortedArr.put(aux, entry.getValue());
        count ++;
      }

      sortedArr.remove(entry.getKey());
    }

    return count;
  }
}
