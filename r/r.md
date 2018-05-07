# Data structures in R

## Vector
One dimension array which contains **same type element**.
Function *c()* and "*1:12*" (for example) will generate vectors.
```r
> x <- 1:3
int [1:3] 1 2 3
> x <- c('a', 'b')
chr [1:2] "a" "b"
```

## Matrix
Two dimension data structure which contains **same type element** . Function *matrix()* is used to created it.
```r
> matrix(1:9, nrow = 3, ncol = 3)
     [,1] [,2] [,3]
[1,]    1    4    7
[2,]    2    5    8
[3,]    3    6    9
> a <- 1:3
> b <- 1:3
> mat <- cbind("row-1" = a,"row-2" =  b)
     row-1 row-2
[1,]     1     4
[2,]     2     5
[3,]     3     6
> str(mat)
int [1:3, 1:2] 1 2 3 4 5 6
 - attr(*, "dimnames")=List of 2
  ..$ : NULL
  ..$ : chr [1:2] "row-1" "row-2"
```
## List
This data structure includes data of **different types**. It is similar to vector but a vector contains similar data but list contains mixed data. A list is created using *list()*.
```r
> x <- list("a" = 2.5, "b" = TRUE, "c" = 1:3)
$a
[1] 2.5

$b
[1] TRUE

$c
[1] 1 2 3
> str(x)
List of 3
 $ a: num 2.5
 $ b: logi TRUE
 $ c: int [1:3] 1 2 3
```
## Data Frame
This data structure is a **special case of list** where each component is of **same length**. Data frame is created using *frame()* function.
```r
> x <- data.frame("SN" = 1:2, "Age" = c(21,15), "Name" = c("John","Dora"))
  SN Age Name
1  1  21 John
2  2  15 Dora
> str(x)
'data.frame':   2 obs. of  3 variables:
 $ SN  : int  1 2
 $ Age : num  21 15
 $ Name: Factor w/ 2 levels "Dora","John": 2 1

```

## Factor
 Factors are used to store **predefined and categorical data**. It can be created using *factor()* function.
```r
> x <- factor(c("single", "married", "married", "single"), levels = c("single", "married", "divorced"));
> x
[1] single  married married single
Levels: single married divorced
```
# Joining data frames in R
![join](https://upload.wikimedia.org/wikipedia/commons/9/9d/SQL_Joins.svg)
```
df1 = data.frame(CustomerId = c(1:6), Product = c(rep("Toaster", 3), rep("Radio", 3)))
df2 = data.frame(CustomerId = c(2, 4, 6), State = c(rep("Alabama", 2), rep("Ohio", 1)))
> df1
  CustomerId Product
  1          1 Toaster
  2          2 Toaster
  3          3 Toaster
  4          4   Radio
  5          5   Radio
  6          6   Radio
>df2
  CustomerId   State
  1          2 Alabama
  2          4 Alabama
  3          6    Ohio
```
## Inner join
![inner join](https://upload.wikimedia.org/wikipedia/commons/1/18/SQL_Join_-_07_A_Inner_Join_B.svg)
```
> merge(x = df1, y = df2, by = "CustomerId")
  CustomerId Product   State
  1          2 Toaster Alabama
  2          4   Radio Alabama
  3          6   Radio    Ohio
```

## Outter join
![outter join](https://upload.wikimedia.org/wikipedia/commons/f/f6/SQL_Join_-_01_A_Left_Join_B.svg)
```
> merge(x = df1, y = df2, by = "CustomerId", all = TRUE)
  CustomerId Product   State
  1          1 Toaster    <NA>
  2          2 Toaster Alabama
  3          3 Toaster    <NA>
  4          4   Radio Alabama
  5          5   Radio    <NA>
  6          6   Radio    Ohio
```

## Left outer
```
> merge(x = df1, y = df2, by = "CustomerId", all.x = TRUE)
  CustomerId Product   State
  1          1 Toaster    <NA>
  2          2 Toaster Alabama
  3          3 Toaster    <NA>
  4          4   Radio Alabama
  5          5   Radio    <NA>
  6          6   Radio    Ohio
```

## Right outer
```
> merge(x = df1, y = df2, by = "CustomerId", all.y = TRUE)
  CustomerId Product   State
  1          2 Toaster Alabama
  2          4   Radio Alabama
  3          6   Radio    Ohio
```

## Cross join
![](https://upload.wikimedia.org/wikipedia/commons/8/82/SQL_Join_-_08_A_Cross_Join_B.svg)
```
> merge(x = df1, y = df2, by = NULL)
   CustomerId.x Product CustomerId.y   State
   1             1 Toaster            2 Alabama
   2             2 Toaster            2 Alabama
   3             3 Toaster            2 Alabama
   4             4   Radio            2 Alabama
   5             5   Radio            2 Alabama
   6             6   Radio            2 Alabama
   7             1 Toaster            4 Alabama
   8             2 Toaster            4 Alabama
   9             3 Toaster            4 Alabama
   10            4   Radio            4 Alabama
   11            5   Radio            4 Alabama
   12            6   Radio            4 Alabama
   13            1 Toaster            6    Ohio
   14            2 Toaster            6    Ohio
   15            3 Toaster            6    Ohio
   16            4   Radio            6    Ohio
   17            5   Radio            6    Ohio
   18            6   Radio            6    Ohio
```

