import java.util.Objects;

class Node
{
  int data;
  Node left, right;

  Node(int item)
  {
    data = item;
    left = right = null;
  }
}

class GfG {
  boolean isFullTree(Node node) {

    if(Objects.isNull(node.right) && Objects.isNull(node.left))
      return true;

    boolean right = isFullTree(node.right);

    boolean left = isFullTree(node.left);

    if(Objects.isNull(node.right) || Objects.isNull(node.left))
      return false;

    return right && left;
  }
}