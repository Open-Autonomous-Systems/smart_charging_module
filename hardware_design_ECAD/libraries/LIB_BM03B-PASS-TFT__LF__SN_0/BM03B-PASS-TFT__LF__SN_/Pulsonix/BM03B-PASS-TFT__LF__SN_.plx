PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//1783792/405177/2.49/5/4/Connector

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r290_100"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.000) (shapeHeight 2.900))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
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
	(patternDef "BM03BPASSTFTLFSN" (originalName "BM03BPASSTFTLFSN")
		(multiLayer
			(pad (padNum 1) (padStyleRef r290_100) (pt -2.000, 3.475) (rotation 0))
			(pad (padNum 2) (padStyleRef r290_100) (pt 0.000, 3.475) (rotation 0))
			(pad (padNum 3) (padStyleRef r290_100) (pt 2.000, 3.475) (rotation 0))
			(pad (padNum 4) (padStyleRef r360_180) (pt -4.350, -1.175) (rotation 0))
			(pad (padNum 5) (padStyleRef r360_180) (pt 4.350, -1.175) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.725) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -5 2.225) (pt 5 2.225) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 5 2.225) (pt 5 -3.475) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 5 -3.475) (pt -5 -3.475) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -5 -3.475) (pt -5 2.225) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -6.05 5.725) (pt 6.05 5.725) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 6.05 5.725) (pt 6.05 -4.275) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 6.05 -4.275) (pt -6.05 -4.275) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -6.05 -4.275) (pt -6.05 5.725) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -5 -3.475) (pt 5 -3.475) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -5 1.225) (pt -5 2.225) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -5 2.225) (pt -3.5 2.225) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 5 1.225) (pt 5 2.225) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 5 2.225) (pt 3.5 2.225) (width 0.1))
		)
	)
	(symbolDef "BM03B-PASS-TFT__LF__SN_" (originalName "BM03B-PASS-TFT__LF__SN_")

		(pin (pinNum 1) (pt 900 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 900 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 900 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 670 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 5) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 700 mils 100 mils) (width 6 mils))
		(line (pt 700 mils 100 mils) (pt 700 mils -300 mils) (width 6 mils))
		(line (pt 700 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 750 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 750 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "BM03B-PASS-TFT__LF__SN_" (originalName "BM03B-PASS-TFT__LF__SN_") (compHeader (numPins 5) (numParts 1) (refDesPrefix J)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "3") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "MP1" (pinName "MP1") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "MP2" (pinName "MP2") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "BM03B-PASS-TFT__LF__SN_"))
		(attachedPattern (patternNum 1) (patternName "BM03BPASSTFTLFSN")
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
		(attr "Manufacturer_Part_Number" "BM03B-PASS-TFT (LF)(SN)")
		(attr "Mouser Part Number" "")
		(attr "Mouser Price/Stock" "")
		(attr "Arrow Part Number" "BM03B-PASS-TFT (LF)(SN)")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/bm03b-pass-tft-lf-sn/jst-manufacturing")
		(attr "Description" "Conn Shrouded Header HDR 3 POS 2mm Solder ST SMD T/R")
		(attr "<Hyperlink>" "http://www.jst-mfg.com/product/pdf/eng/ePA-F.pdf")
		(attr "<Component Height>" "8.9")
		(attr "<STEP Filename>" "BM03B-PASS-TFT__LF__SN_.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
