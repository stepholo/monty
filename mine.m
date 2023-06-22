# This is a monty file that contains the test cases used in testing the interperator for monty file bytecode
# There are different test cases
# Please use it wisely
# Use the hash-tag "#" operator to comment out the sections you dont require and uncomment the parts you need
# Feel free to add more test cases

# Case 1 - test for the spaces and tabs
#push 0
#push 1
#push 2
#  push 3
#                   pall
#push 4
#   push 5
#     push    6
#pall

# Case 2 - test for blank lines and any additional text after the opcode
#push 0 Push 0 onto the stack
#push 1 Push 1 onto the stack
#
#push 2
#  push 3
#                   pall
#
#
#
#push 4
#
#   push 5
#      push    6
#
#pall This is the end of our program. Monty is awesome!

# Case 3 - Test for push and pall
#push 1
#push 2
#push 3
#pall

# Case 4 -
