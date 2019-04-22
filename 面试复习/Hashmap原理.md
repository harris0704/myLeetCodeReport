# hashmap底层实现原理

![](https://res.cloudinary.com/dyydsmpfn/image/upload/v1555851631/blog/map.png)

&emsp;&emsp;TreeMap是基于树的实现，HashMap HashTable ConcurrentHashTable是基于hash表的实现。HashTable是线程安全的；ConcurrentHashMap也是线程安全的，但性能比HashTable好很多，HashTable是锁整个Map对象，而ConcurrentHashMap是锁Map的部分结构。
&emsp;&emsp;Map数据结构，就是key-value对。接下来重点介绍HashMap。
```java
// 初始化
Map<int, int> m = new HashMap<>();
// 构造函数
public HashMap(){
    this.loadFactor = DEFAULT_LOAD_FACTOR;
}
// 初始化一个负载因子， 默认为0.75f
// 属性： key value next（用来标记Node节点的下一个元素）
// 接下来put时，使用了一个方法hash()
// 对冲突的处理
// 在JDK1.8中加入了红黑树是为防止哈希表碰撞，当链表长度为8时，及时转化红黑树，提高map的效率。
```

