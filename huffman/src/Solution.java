public class Solution {

  public static void main(String[] args) {

    final Solution solution = new Solution();

    final Node leafA = new Node();
    leafA.data = 'A';

    final Node leafB = new Node();
    leafB.data = 'B';

    final Node leafC = new Node();
    leafC.data = 'C';

    final Node leafNull = new Node();
    leafNull.right = leafC;
    leafNull.left = leafB;


    final Node root = new Node();
    root.right = leafA;
    root.left = leafNull;


    solution.decode("1001011", root);

  }

  void decode(String s, Node root) {
    String word = "";
    Node c = root;
    for (int i = 0; i < s.length(); i++) {
      c = s.charAt(i) == '1' ? c.right : c.left;
      if (c.left == null && c.right == null) {
        word = word.concat(String.valueOf(c.data));
        c = root;
      }
    }
    System.out.print(word);
  }

}

class Node {
  public  char data;
  public  Node left, right;
}

