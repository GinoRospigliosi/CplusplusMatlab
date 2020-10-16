
%GinoRospigliosi
%HW#4 Section:0201
function x=matrixmult(A,B)
%Matrix of mxn size
%m denotes rows
%n denotes columns
[mA nA]=size(A);
[mB nB]=size(B);
%Initialize Sum
sum=0;
%Check Dimensions
if nA==mB;
%For loops iterations based on matrix size(outer dimension mA,nB)
%(inner dimension nA,mB)

for i=1:mA;
    for j=1:nB;
        for k=1:nA;
           %Multiplying and adding indivual matrix parts like dot product
           sum=sum+ A(i,k)*B(k,j);
        end
        x(i,j)=sum;
        sum=0;
    end
end
%Matlab multiplication for validation
disp(A*B)
end
end
