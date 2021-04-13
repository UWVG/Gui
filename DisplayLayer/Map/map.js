new QWebChannel(qt.webChannelTransport,
function(channel){
    var webobj = channel.objects.context;
    window.foo = webobj;
    //这里修改也会触发事件只要内容发生改变都会传递给
    //webobj.content = 'This is web content';
    
   

var icon = new AMap.Icon();
var polyline = null;
//回调函数
var callback_click= function(ev)
{
    var marker = new AMap.Marker({map:map,});
    marker.setDraggable(true);
    marker.setIcon(icon);
    marker.setPosition(new AMap.LngLat(ev.lnglat.R,ev.lnglat.Q));
    marker.on("dragging",callback);
    marker.on("rightclick",callback_rightclick);
    console.log(map.getAllOverlays("marker"));
    draw_line();
}
var draw_line = function()
{
    var msg = [];
    msg.push(1);
    if(polyline)
    {
        map.remove(polyline);
    }
    var path = [];
    var markers = map.getAllOverlays("marker");
    for(var i = 0;i<markers.length;i++)
    {
        msg.push(markers[i].getPosition().R);
        msg.push(markers[i].getPosition().Q);
        path[i] = new AMap.LngLat(markers[i].getPosition().R,markers[i].getPosition().Q);
    }
    polyline = new AMap.Polyline({path:path,borderWeight: 2, // 线条宽度，默认为 1
        strokeColor: 'red', // 线条颜色
        lineJoin: 'round' // 折线拐点连接处样式
        });
    map.add(polyline);
    webobj.onMsg(msg);
}
var callback_rightclick = function(ev)
{
    this.off("dragging",callback);
    map.remove(this);
    this.off("rightclick",callback_rightclick);  
    console.log(map.getAllOverlays("marker"));
    draw_line();
}

var callback = function(ev)
{
    this.setLabel({
    offset: new AMap.Pixel(10, -30),  //设置文本标注偏移量
    content: "<div>status:<br>v: <br>"+"lng:"+this.getPosition().R+"<br>lat:"+this.getPosition().Q+"<br></div>", //设置文本标注内容
    direction: 'top-right' //设置文本标注方位
    });
    draw_line();
}



//主要的map
var map = new AMap.Map('container', {
    resizeEnable: true, //是否监控地图容器尺寸变化
    dragEnable: true, // 地图是否可通过鼠标拖拽平移，默认为true
    keyboardEnable: false, //地图是否可通过键盘控制，默认为true
    doubleClickZoom: false, // 地图是否可通过双击鼠标放大地图，默认为true
    zoomEnable: true, //地图是否可缩放，默认值为true
    rotateEnable: false, // 地图是否可旋转，3D视图默认为true，2D视图默认false
    layers: [new AMap.TileLayer.Satellite()],
    zoom:17, //初始化地图层级
    center: [ 126.68049433,45.77821917] //初始化地图中心点
});



var marker = new AMap.Marker({map:map,});
marker.setDraggable(true);
marker.setIcon(icon);
marker.visible = false;
marker.on("dragging",callback);
gps = [126.68049433,45.77821917];
AMap.convertFrom(gps, 'gps', function (status, result) {
    if (result.info === 'ok') {
    var lnglats = result.locations; // Array.<LngLat>
    marker.setPosition(new AMap.LngLat(lnglats[0].R,lnglats[0].Q));
    marker.visible = true;
    }
});
map.on("click",callback_click);




var updateattribute=function(text)
{
    switch(text.cmd){
        case 1:
            document.write(text.a);
            document.write(text.b);
            document.write(text.c);
            break;
        case 2:
            map.setCenter(marker.getPosition());
            break;
        case 3:
            map.setZoom(18);
            break;
    }	
}
webobj.contentChanged.connect(updateattribute);
});
    
    