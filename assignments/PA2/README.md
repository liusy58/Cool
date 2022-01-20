

### Undefined reference to `yylex'
First I directly install flex by `sudo apt-get install flex`, but flex 2.6.x changed the way `yylex` behaves.
But we can use `sudo apt-get install -y flex-old` to solve this problem.
