/**
 * A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
 *
 * Complete the function provided for you in your editor. It has one parameter: a pointer to a Node object named head that points to the head of a linked list.
 * Your function must return a boolean denoting whether or not there is a cycle in the list. If there is a cycle, return true; otherwise, return false.
 *
 * Note: If the list is empty, head will be null.
 */

public class Solution {

  static boolean hasCycle(SinglyLinkedListNode head) {

    if(head == null) return false;

    SinglyLinkedListNode slow = head;
    SinglyLinkedListNode fast = head.next;

    while(fast != null && fast.next != null){
      if(slow == fast) return true;

      slow = slow.next;
      fast = fast.next.next;
    }

    return false;
  }

}

class SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode next;
}