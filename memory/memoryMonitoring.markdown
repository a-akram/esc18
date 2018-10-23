---
title: Simple Memory Monitoring
layout: main
category: memory
---

Open [memoryTest.cpp]({{site.exercises_repo}}/hands-on/memory/memoryTest.cpp) and look to what the functions
``cArray``, ``cppVector`` and ``cppVectorFill`` do.

compile it
{% highlight bash %}
./compile memoryTest.cpp
{% endhighlight %}

run it a first time and follow the output and the code
<br>
Open a second window on the same machine and start
{% highlight bash %}
./psloop
{% endhighlight %}
(look in the file what psloop does!)
<br>
start "memoryTest" again under ``strace``
{% highlight bash %}
strace -tt -e trace=memory ./a.out
{% endhighlight %}
find out its process-Id (in the following denoted as _thePid_
<br>
Open a third window on the same machine and issue
{% highlight bash %}
cat /proc/meminfo
cat /proc/thePid/smaps
pmap -X thePid
{% endhighlight %}
<p>
step through the program and correlate the actions in the code with what you observe with these tools

