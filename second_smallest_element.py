import random

def second_smallest_element(l):
    if l[0] < l[1]:
        s1 = 0
        s2 = 1
    else:
        s1 = 1
        s2 = 0
    for i in range (2, len(l)):
        if l[i] < l[s2]:
            if l[i] < l[s1]:
                # i < s1 < s2
                s2 = s1
                s1 = i
            else:
                # s1 < i < s2
                s2 = i
    # for checking
    print("list: {}, smallest: {} (index {}), second smallest: {} (index {})".format(l, l[s1], s1, l[s2], s2))
    # return second smallest element and its index
    return s2, l[s2]

randomlist = [i for i in range(1, 11)]
random.shuffle(randomlist)
second_smallest_element(randomlist)
