PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//11527318/405177/2.49/5/4/Connector

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r290_100"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.000) (shapeHeight 2.900))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "c45_h90"
		(holeDiam 0.9)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 0.450) (shapeHeight 0.450))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0.450) (shapeHeight 0.450))
	)
	(padStyleDef "c122_h244"
		(holeDiam 2.44)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.220) (shapeHeight 1.220))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.220) (shapeHeight 1.220))
	)
	(padStyleDef "r360_180"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.800) (shapeHeight 3.600))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "BM03BPASS1TFTLFSN" (originalName "BM03BPASS1TFTLFSN")
		(multiLayer
			(pad (padNum 1) (padStyleRef r290_100) (pt 2.000, 3.075) (rotation 0))
			(pad (padNum 2) (padStyleRef r290_100) (pt 0.000, 3.075) (rotation 0))
			(pad (padNum 3) (padStyleRef r290_100) (pt -2.000, 3.075) (rotation 0))
			(pad (padNum 4) (padStyleRef c45_h90) (pt 4.200, 1.825) (rotation 90))
			(pad (padNum 5) (padStyleRef c122_h244) (pt -4.200, 1.825) (rotation 90))
			(pad (padNum 6) (padStyleRef r360_180) (pt 4.350, -1.575) (rotation 0))
			(pad (padNum 7) (padStyleRef r360_180) (pt -4.350, -1.575) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt -0.085, 1.213) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -5 2.625) (pt 5 2.625) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 5 2.625) (pt 5 -3.075) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 5 -3.075) (pt -5 -3.075) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -5 -3.075) (pt -5 2.625) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -6.42 6.8) (pt 6.25 6.8) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 6.25 6.8) (pt 6.25 -4.375) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 6.25 -4.375) (pt -6.42 -4.375) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -6.42 -4.375) (pt -6.42 6.8) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 2 5.8) (pt 2 5.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt 2, 5.75) (radius 0.05) (startAngle 90.0) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 2 5.7) (pt 2 5.7) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt 2, 5.75) (radius 0.05) (startAngle 270) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 2 5.8) (pt 2 5.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt 2, 5.75) (radius 0.05) (startAngle 90.0) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3 -3.1) (pt 3.1 -3.1) (width 0.1))
		)
	)
	(symbolDef "BM03B-PASS-1-TFT_LF__SN_" (originalName "BM03B-PASS-1-TFT_LF__SN_")

		(pin (pinNum 1) (pt 900 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 900 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 900 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 5) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 700 mils 100 mils) (width 6 mils))
		(line (pt 700 mils 100 mils) (pt 700 mils -300 mils) (width 6 mils))
		(line (pt 700 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 750 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 750 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "BM03B-PASS-1-TFT_LF__SN_" (originalName "BM03B-PASS-1-TFT_LF__SN_") (compHeader (numPins 5) (numParts 1) (refDesPrefix J)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "3") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "MP1" (pinName "MP1") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "MP2" (pinName "MP2") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "BM03B-PASS-1-TFT_LF__SN_"))
		(attachedPattern (patternNum 1) (patternName "BM03BPASS1TFTLFSN")
			(numPads 5)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "MP1")
				(padNum 5) (compPinRef "MP2")
			)
		)
		(attr "Manufacturer_Name" "JST (JAPAN SOLDERLESS TERMINALS)")
		(attr "Manufacturer_Part_Number" "BM03B-PASS-1-TFT(LF)(SN)")
		(attr "Mouser Part Number" "")
		(attr "Mouser Price/Stock" "")
		(attr "Arrow Part Number" "")
		(attr "Arrow Price/Stock" "")
		(attr "Description" "Wire-To-Board Connector, PA Series, Surface Mount, Header, 3, 2 mm, Tin Plated Contacts RoHS Compliant: Yes")
		(attr "<Hyperlink>" "https://datasheet.lcsc.com/szlcsc/2002281632_JST-Sales-America-BM03B-PASS-1-TFT-LF-SN_C485351.pdf")
		(attr "<Component Height>" "8.9")
		(attr "<STEP Filename>" "BM03B-PASS-1-TFT_LF__SN_.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
