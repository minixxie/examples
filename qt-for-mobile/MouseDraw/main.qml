import QtQuick 2.4
import QtQuick.Window 2.2

Window {
	visible: true
	width: 300
	height: 400

	Canvas {
		id: canvas
		anchors.fill: parent

		property var lines: [] // [{'x':100,'y':100},{'x':200,'y':200},{'x':210,'y':300}]
		onPaint: paintIt();

		function paintIt() {
			var ctx = canvas.getContext("2d");
			ctx.strokeStyle = "rgb(0,255,0)";
			ctx.lineWidth = 2;
			if ( canvas.lines.length > 0 )
			{
				ctx.beginPath();
				for ( var i = 0 ; i < canvas.lines.length ; i++ )
				{
					ctx.moveTo(canvas.lines[i].x1, canvas.lines[i].y1);
					ctx.lineTo(canvas.lines[i].x2, canvas.lines[i].y2);
				}
			}
			ctx.stroke();
			ctx.closePath();
		}
	}


	MouseArea {
			anchors.fill: canvas

			property var lastMouse
			onPressed: {
				lastMouse = {'x': mouse.x, 'y': mouse.y};
			}

			onPositionChanged: {
				console.debug("onPositionChanged...");
				if ( pressed )
				{
					console.debug("x,y=" + mouse.x + "," + mouse.y);
					canvas.lines.push(
						{'x1':lastMouse.x, 'y1':lastMouse.y, 'x2':mouse.x, 'y2':mouse.y} );
					lastMouse = {'x': mouse.x, 'y': mouse.y};
					canvas.requestPaint();
				}
			}

	}
}
