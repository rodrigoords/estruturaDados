import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) {

        int[] flowers = new int[]{1,3,5,7,9};
        System.out.println(Main.getMinimumCost(2, flowers));
    }

    static int getMinimumCost(int k, int[] c) {

        int total = 0;
        PriorityQueue<Integer> sorted = new PriorityQueue<>(Comparator.reverseOrder());

        for (int i = 0; i < c.length; i++) {
            sorted.add(c[i]);
        }

        int count = 0;
        while (!sorted.isEmpty()){

            for (int i = 0; i < k; i++) {
                final Integer polled = sorted.poll();
                if(polled == null)
                    break;
                total = total + (count + 1) * polled;
            }

            count ++;
        }

        return total;

    }
}
