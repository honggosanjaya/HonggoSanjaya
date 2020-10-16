$(document).on('click','#toptobottom',function(){
   $('html,body').animate({scrollTop:0},500);
   return false;
   
});

$(document).scroll(function(e) {
     var scrollPos = $(this).scrollTop();
     if(scrollPos < 100){
       $('#toptobottom').addClass('scroll-hide');
}else{
      $('#toptobottom').removeClass('scroll-hide');
}
});