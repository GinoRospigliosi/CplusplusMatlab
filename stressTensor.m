%GinoRospigliosi
%HW#4 Section:0201
%Normalize
n1=fext/norm(fext);
n3=fcom/norm(fcom);
%Cross Product
n2=cross(n3,n1);
MatrixX=[n1,n2,n3];
eig1=norm(fext);
eig3=-1*norm(fcom);
eig2=-1*eig1-eig3;
MatrixB=[eig1 0 0; 0 eig2 0; 0 0 eig3];
%Matrix Multiplication
T=MatrixX*MatrixB*inv(MatrixX);
f=T*n
