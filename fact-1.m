function f = fact(n)

  f = 1;

  for k=n:-1:1 % or k=1:n 
    f = f*k;
  end

% Note: this code will actually also produce the
% correct result fact(0)=1.  Try it and see!

% (Of course, fact(-1) will give an incorrect
% answer of 1 as well, so there is still work to 
% do there!)

% Test: fact(7) should give "ans = 5040"  
  
end
  
