function [  ] = plotRange( array, from, to )
%plots array from an x value to an x value

i = 1;

while array(1,i) < from
    i = i+1;
end
startI = i;
while array(1, i) < to
    i = i+1;
end
endI = i;

plot(array(1,startI:endI),array(2,startI:endI));


end

