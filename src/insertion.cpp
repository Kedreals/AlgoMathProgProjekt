# i n c l u d e   " s o r t i n g . h p p " 
 # i n c l u d e   < i o s t r e a m > 
 u s i n g   n a m e s p a c e   s t d ; 
 
 / * F u n k t i o n ,   d i e   d i e   P o s i t i o n   i m   A r r a y   a u s g i b t , 
 i n   w e l c h e r   d e r   W e r t   " k e y "   e i n g e f � g t   w e r d e n   s o l l . * /                                                                                                                                                         
 i n t   B i n a r y S e a r c h ( i n t   a [ ] ,   i n t   k e y ,   i n t   L a e n g e ) 
 { 
 	 i n t   l i n k s   =   0 ; 
 	 i n t   r e c h t s   =   L a e n g e - 1 ; 
 	 
 	 w h i l e   ( l i n k s < = r e c h t s ) 
 	 { 
 	 	 i n t   m i t t e   =   l i n k s   +   ( ( r e c h t s - l i n k s ) / 2 ) ; 
 	 	 
 	 	 / / Z u e r s t   w i r d   i n   d e r   M i t t e   d e s   A r r a y s   g e s u c h t . 
 	 	 i f   ( a [ m i t t e ] = = k e y ) 
 	 	 	 r e t u r n   m i t t e ; 
 	 	 e l s e 
 	 	 	 / * F a l l s   " k e y "   k l e i n e r   b z w .   g r � � e r   i s t   a l s   d e r   M i t t e l w e r t , k a n n   d e r   
 	 	 	 T e i l   r e c h t s   b z w .   l i n k s   v o m   M i t t e l w e r t   i g n o r i e r t   w e r d e n . * / 
 	 	 	 i f   ( a [ m i t t e ] > k e y ) 
 	 	 	 	 r e c h t s = m i t t e - 1 ; 
 	 	 	 e l s e 
 	 	 	 	 l i n k s = m i t t e + 1 ; 
 	 } 
 	 / * F a l l s   l i n k s > r e c h t s ,   m u s s   d a s   E l e m e n t   a n   d e r   S t e l l e 
 	 " l i n k s "   e i n g e f � g t   w e r d e n . * /   
 	 r e t u r n   l i n k s ; 
 } 
 
 / * F u n k t i o n ,   d i e   e i n e n   A r r a y   d u r c h   E i n f � g e n   m i t t e l s   b i n � r e r 
 S u c h e   s o r t i e r t . * / 
 v o i d   I n s e r t i o n S o r t ( i n t   L a e n g e ,   i n t   a [ ] ) 
 { 
         i n t   i ,   p o s i t i o n ,   j ,   k e y ; 
   
         f o r   ( i   =   1 ;   i   <   L a e n g e ;   i + + ) 
         { 
                 
                 k e y   =   a [ i ] ; 
                 
                 / * A l s   W e r t   f � r   d i e   L � n g e   w i r d   h i e r   i ,   b e g i n n e n d   b e i   1   e i n g e s e t z t , 
                 d a   d i e   b i n � r e   S u c h e   n u r   m i t   s o r t i e r t e n   A r r a y s   f u n k t i o n i e r t . 
 	 	 E s   s o l l   d i e   P o s i t i o n   d e s   E l e m e n t e s   " k e y "   e r m i t t e l t   w e r d e n . * / 
                 p o s i t i o n   =   B i n a r y S e a r c h ( a ,   k e y ,   i ) ; 
   	 	 
   	 	 / / D i e   f o r - s c h l e i f e   f � g t   d a s   " k e y " - E l e m e n t   a n   d e r   g e f u n d e n e n   P o s i t i o n   e i n . 
                 f o r   ( j = i ; j > p o s i t i o n ; j - - ) 
                 { 
                         a [ j ]   =   a [ j - 1 ] ; 
                 } 
                 a [ p o s i t i o n ] = k e y ; 
         } 
 } 
 