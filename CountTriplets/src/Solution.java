import java.util.*;

/**
 * You are given an array and you need to find number of tripets of indices (i,j,k) such that the elements at those indices are in geometric progression for a given common ratio r and i < j < k.
 *
 * For example, arr = [1,4,16,64]. If r = 4, we have [1,4,16] and [4, 16, 64] at indices (0,1,2) and (1,2,3).
 *
 * Function Description
 *
 * Complete the countTriplets function in the editor below. It should return the number of triplets forming a geometric progression for a given r as an integer.
 *
 * countTriplets has the following parameter(s):
 *
 * arr: an array of integers
 * r: an integer, the common ratio
 *
 * Constraints
 *
 * 1 <= r <= 10^9
 * 1 <= arr[i] <= 10^9
 *
 * Output Format
 *
 * Return the count of triplets that form a geometric progression.
 */
public class Solution {


  public static void main(String[] args){

    long ratio = 5;
    final List<Long> values = Arrays.asList(1L, 5L, 5L, 25L, 125L);

    System.out.println(Solution.countTriplets(values, ratio));
  }

  // Complete the countTriplets function below.
  static long countTriplets(List<Long> arr, long r) {

    long total = 0;
    Map<Long, Long> secondPosition = new HashMap<>();
    Map<Long, Long> thirdPosition = new HashMap<>();

    for (int i = 0; i < arr.size(); i++) {

      final Long value = arr.get(i);

      total = total + thirdPosition.getOrDefault(value, 0L);

      final Long secondCount = secondPosition.get(value);
      if(secondCount != null){
        final Long orDefault = thirdPosition.getOrDefault(value * r, 0L);
        thirdPosition.put(value * r, orDefault + secondCount);
      }

      secondPosition.put(value * r, secondPosition.getOrDefault(value * r, 0L) + 1);

    }

    return total;

  }


}
