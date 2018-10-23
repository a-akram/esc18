---
title: A look to your Hardware
layout: main
category: Architecture
---

To know which is the architecture of the machine you are logged in use
{% highlight bash %}lscpu{% endhighlight %}
googling for the Model Name will provide more detail.

More details about the NUMA setup can be obtained with {% highlight bash %}numactl -H{% endhighlight %}

to kwow which architecture the compiler believe to be the ``native`` one use
{% highlight bash %}
 gcc -march=native -Q --help=target | grep march | awk '{ print $2 }'
{% endhighlight %}

caveat: if you are logged on a virtual machine all those info may be bogus...
