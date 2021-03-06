(*
 *  CS164 Fall 94
 *
 *  Programming Assignment 1
 *    Implementation of a simple stack machine.
 *
 *  Skeleton file
 *)



(*
* Your program need not do any error checking
*)
class List {
   -- Define operations on empty lists.

   isNil() : Bool { true };

   -- Since abort() has return type Object and head() has return type
   -- Int, we need to have an Int as the result of the method body,
   -- even though abort() never returns.

   head()  : String { { abort(); ""; } };

   -- As for head(), the self is just to make sure the return type of
   -- tail() is correct.

   tail()  : List { { abort(); self; } };


   len()  : Int {0};

   -- When we cons and element onto the empty list we get a non-empty
   -- list. The (new Cons) expression creates a new list cell of class
   -- Cons, which is initialized by a dispatch to init().
   -- The result of init() is an element of class Cons, but it
   -- conforms to the return type List, because Cons is a subclass of
   -- List.

   cons(i : String) : List {
      (new Cons).init(i, self)
   };
};


class Cons inherits List {

   str : String;	-- The element in this list cell

   rest : List;	-- The rest of the list

   isNil() : Bool { false };

   head()  : String { str };

   tail()  : List { rest };

   len()   : Int  { 1 + rest.len()};

   init(i : String, r : List) : List {
      {
         str <- i;
         rest <- r;
         self;
      }
   };

};



class Main inherits IO {
   newline() : Object {
	   out_string("\n")
   };

   prompt() : String {
      {
         out_string(">");
         in_string();
      }
   };

   print_list(l : List) : Object {
      if l.isNil() then out_string("")
      else {
            out_string(l.head());
            out_string("\n");
            print_list(l.tail());
         }
      fi
   };


   swap(l : List) : List{
      l <- l.tail()
      let str1:String<-l.head();
      l <- l.tail();
      let str2:String<-l.head();
      l <- l.cons(str2);
      l <- l.cons(str1);
      l;      
   };

   addtolist(l : Cons) : Cons{
      let z : A2I <- new A2I ;
      l <- l.tail();
      let str1 :String <- l.head();
      l <- l.tail();
      let str2 :String <- l.head();
      let num1 <- z.a2i(str1); 
      let num2 <- z.a2i(str2);

      let num3 <- num1+num2;
      let str3 <- z.i2a(num3);
      l <- l.cons(str3);
      l;      
   };


   evaluate(l : Cons) : Cons{
      if l.isNil() or l.len() <= 2 then
         return l;
      else
         let str : String <- l.head();
         if str = "s" then{
            l <- swap(l) ; 
         }
         else 
            if str = "+" then
               l <- addtolist(l);
            fi
         fi
      fi
      l
   };

   main() : Object {
      mylist : List;
      mylist <- new List;
      while true loop
        let s : String <- prompt() 
         if s = "x" then
            break;
         else 
            if s = "e" then
               mylist <- evaluate(mylist);
            else
               mylist <- mylist.cons(s);
         fi
      pool
      
   };

};
