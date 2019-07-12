public class Solution {
  public static long count2s(long n) {

    long total = 0;

    for(int i = 0; i <= n; i++) {

      String s = String.valueOf(i);

      for (int i1 = 0; i1 < s.toCharArray().length; i1++) {
        if("2".equals(String.valueOf(s.charAt(i1))))
          total++;
      }
    }

    return total;
  }

  public static void main(String[] args){
    System.out.println(Solution.count2s(22));
  }
}
