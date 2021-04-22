/*Initial configuration of Circular Queue is a, b, __, __, c . We see whenever new element will be added it will added to first blank therefore First pointer points to element c and last pointer points to element b

enqueue x==>>a, b, x, __, c   first pointer points to element c and last pointer points to element x

dequeue ==>>a, b, x, __, __   first pointer points to element a and last pointer points to element x

enqueue y==>>a, b, x, y, __      first pointer points to element a and last pointer points to element y

dequeue==>> __, b, x, y, __      first pointer points to element b and last pointer points to element y

dequeue==>>__, __, x, y, __     first pointer points to element x and last pointer points to element y*/
