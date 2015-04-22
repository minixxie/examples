package com.simon;

import android.content.Intent;
import android.os.Environment;
import java.io.File;
import android.net.Uri;
import android.provider.MediaStore;

class MyActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
	public void callExternalCamera()
	{
		String action = "android.media.action.IMAGE_CAPTURE";
		Intent intent = new Intent(action);

		File extDir = Environment.getExternalStorageDirectory();
		String filename = "camera.jpg";
		File photo = new File(extDir, filename);

		Uri takePhotoSavedUri = Uri.fromFile( photo );

		intent.putExtra( MediaStore.EXTRA_OUTPUT, takePhotoSavedUri );

		int SHOOT_PHOTO = 1;
		startActivityForResult(intent, SHOOT_PHOTO);
	}
}
