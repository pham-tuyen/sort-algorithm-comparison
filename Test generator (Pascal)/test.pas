uses crt;
var i,k:integer;
f:text;
a:array[1..10000] of integer;
procedure sort(l,r:integer);
var i,j,x,m:integer;
begin
x:=a[(l+r) div 2];
i:=l;j:=r;
repeat
while a[i]<x do inc(i);
while x<a[j] do dec(j);
if i<=j then
begin
m:=a[i];a[i]:=a[j];a[j]:=m;
inc(i);dec(j);
end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;
begin
randomize;
for i:=1 to 10000 do a[i]:=random(10001);
assign(f,'d:/sort/test/random.txt');rewrite(f);
for i:=1 to 10000 do write(f,a[i],' ');
close(f);sort(1,10000);
assign(f,'d:/sort/test/inc.txt');rewrite(f);
for i:=1 to 10000 do write(f,a[i],' ');
close(f);
assign(f,'d:/sort/test/dec.txt');rewrite(f);
for i:=10000 downto 1 do write(f,a[i],' ');
close(f);
assign(f,'d:/sort/test/nrinc.txt');rewrite(f);
for i:=1 to 200 do begin
k:=a[random(10001)];a[random(10001)]:=a[random(10001)];a[random(10001)]:=k;
end;
for i:=1 to 10000 do write(f,a[i],' ');
close(f);
end.
