// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Global/OC2Struct.h"
#include "Global/OC2Enum.h"

#include "Global/Data/IngredientDataTable.h"
#include "Global/Data/OrderDataTable.h"

#include "OC2GlobalData.generated.h"

class AIngredient;

/**
 * 
 */
UCLASS()
class OVERCOOKED2_API UOC2GlobalData : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * 재료의 유형을 가져옵니다.
	 *
	 * @param RowName 데이터 테이블에서 찾을 행의 이름입니다.
	 * @return 해당 재료의 유형(EIngredientType)입니다.
	 */
	UFUNCTION(BlueprintCallable)
	static EIngredientType GetIngredientType(UWorld* World, const FName& RowName);
	/**
	 * 특정 재료의 조리 데이터를 가져옵니다.
	 *
	 * @param RowName 데이터 테이블에서 찾을 행의 이름입니다.
	 * @return 해당 재료의 조리 데이터 배열(TArray<FIngredientCookDataRow>)입니다.
	 */
	UFUNCTION(BlueprintCallable)
	static const TArray<FIngredientCookDataRow>& GetIngredientCookDataRows(UWorld* World, const FName& RowName);
	/**
	 * 특정 재료의 스태틱 메시를 가져옵니다.
	 *
	 * @param RowName 데이터 테이블에서 찾을 행의 이름입니다.
	 * @return 해당 재료의 스태틱 메시(UStaticMesh*)입니다.
	 */
	UFUNCTION(BlueprintCallable)
	static UStaticMesh* GetIngredientStaticMesh(UWorld* World, const FName& RowName);
	/**
	 * 주어진 재료 타입(EIngredientType)에 해당하는 데이터 테이블 행 이름을 반환합니다.
	 *
	 * @param IngredientType 조회할 재료의 타입입니다.
	 * @return FName 해당 재료의 데이터 테이블 행 이름을 반환합니다. 유효하지 않은 타입일 경우 빈 FName("")을 반환합니다.
	 */
	UFUNCTION(BlueprintCallable, Category = "Global|Data")
	static FName GetIngredientDataTableRowName(UWorld* World, EIngredientType IngredientType);
	/**
	 * 특정 재료의 데이터 테이블 행 데이터의 주소값을 가져옵니다.
	 *
	 * @param World 게임 월드 객체입니다.
	 * @return FIngredientDataRow 해당 재료의 데이터 테이블 행 데이터입니다.
	 */
	UFUNCTION(BlueprintCallable, Category = "Global|Data")
	static const FIngredientDataRow& GetIngredientDataRow(UWorld* World, const FName& RowName);

	static const FIngredientDataRow& GetIngredientDataRow(UWorld* World, EIngredientType IngredientType);

	static FPlateInitData GetPlateMesh(UWorld* World, TArray<FRecipe>& Recipes);

	static FPlateInitData GetPlateMesh(UWorld* World, const TArray<class AIngredient*>& Ingredients);

	static FOrder GetOrderByStageAndIndex(UWorld* World, EOC2Stage CurStage, int Index);
};
