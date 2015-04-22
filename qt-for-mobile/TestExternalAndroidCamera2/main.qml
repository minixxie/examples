import QtQuick 2.4
import QtQuick.Window 2.2

import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Window {
	visible: true
	width: 320
	height: 480
	Button {
		id: takePhotoButton
		anchors.top: parent.top
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.margins: 10
		width: 300
		height: 40
		style: ButtonStyle {
			background: Rectangle {
				color: control.pressed ? Qt.lighter("#0080ff") : "#0080ff"
				radius: 4
			}
			label: Label {
				anchors.fill: parent
				color: "#ffffff"
				text: "Take Photo"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}
		onClicked: {
			myController.callExternalCamera();
		}
	}
	Rectangle {
		anchors.top: takePhotoButton.bottom
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.bottom: parent.bottom
		anchors.margins: 10
		color: "#f0f0f0"
		Image {
			anchors.fill: parent
			source: myController.imagePath == "" ? "" : "file:" + myController.imagePath
			fillMode: Image.PreserveAspectFit
		}
	}
}
