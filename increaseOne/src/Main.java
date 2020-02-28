public class Main {

  public static void main(String[] args){
    final Main main = new Main();
    int[] number = new int[]{8,9,9,4};
    final int[] increased = main.increase(number);

    for (int i : increased) {
      System.out.print(i);
    }
  }

  public int[] increase(int[] number){

    int carry = 1;
    int[] result = new int[number.length];

    for (int i = number.length - 1; i >= 0 ; i--) {
      int sum = number[i] + carry;

      if(sum == 10) carry = 1;
      else carry = 0;

      result[i] = sum % 10;

    }

    if(carry == 1){
      final int[] ints = new int[number.length + 1];
      ints[0] = 1;
      result = ints;
    }

    return result;
  }
}
