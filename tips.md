#windows socket
<p>计算校验和时，不需要做字节序变换。由于按小端序计算得到的校验和与按大端序计算得到的校验和刚好相反，在将小端序计算得到的校验和按小端序写入后，校验和字节序与按大端序计算得到的校验和一致。设本机是小端机，若本机上计算得到一个值为0x1234的校验和，则按网络字节序(大端序)计算得到的校验和必为0x3421，本机按小端序再将0x1234写入协议单元首部时，自动转换为0x3421，与按网络字节序计算得到的校验和一致。
</p>

#spark
##start with spark
1. **create a spark session**
<br>spark = SparkSession.builder.appName(yourAppName).getOrCreate()
2. **load text file by session**
<br>f = spark.read.text(textFile)
3. **do with f, where f is a DataFrame Object**
4. **close spark session:**
<br>spark.stop()
5. **about pyspark.sql.DataFrame**
<br>DataFrame.cache(): used to persist the object in memory.
<br>DataFrame.select(Column): used to select row satisfied with Column, where Column stands for an row constrained condition.
<br>DataFrame.count(): return the number of rows.
<br>DataFrame.collect(): return all Row Objects related to DataFrame.
<br>DataFrame.first(): return first row of DataFrame.
6. **about pyspark.sql.Column**
<br>Column.name(str newName): return a Column named newName.<
<br>Column.alias(str newName): the same as Column.name(newName).
7. **about pyspark.sql.functions**

##start with RDD(http://spark.apache.org/docs/latest/rdd-programming-guide.html)
1. **introduction**
<br>The main abstraction Spark provides is a resilient distributed dataset (RDD), which is a collection of elements partitioned across the nodes of the cluster that can be operated on in parallel.
<br>A second abstraction in Spark is shared variables that can be used in parallel operations.
<br>RDD have two operations, transformations and actions. Transformations is lazy, the data would be loaded only when actions occured.
2. **basic steps**
<br>create a SparkContext to initialize spark
<br>create RDDs
3. **about pyspark.SparkContext**
4. **about RDD operations**
<br>transformations
<br>actions
<br>"shuffle"
5. **about RDD Persistence**
6. **about Shared Variables**
<br>Broadcast Variables
<br>Accumulator Variables
<br>AccumulatorParam